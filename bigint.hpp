#pragma once
#include <iostream>
#include "bigint.hpp"
#include <stdexcept>
#include <vector>

/**
 * In this program we present an abitrary-precision integer of a bigint class
 * the following operators are implemented addition, subtraction, mutltiplication, negation, comparision, insertion, increment and decrement.
 */
class bigint
{
public:
    /**
     * @brief brief description The default constructor.
     * @return  zero.
     */
    bigint();
    /**
     * @brief brief description Constructor that takes a signed 64-bit integer.
     * @return  output an arbitrary precision integer.
     * @param number-> signed 64-bit integer.
     */
    bigint(int64_t number);

    /**
     * @brief constructor that takes string of digits.
     * @param str ->The string that contain the integer.
     * We throw error if the string contains invalid character or its empty.
     * @return  ouput an arbitrary-precision integer.
     */
    bigint(const std::string &str);

    /**
     * @brief  the operator += to add two bigint objects.
     * @param num2 ->is  added to current object.
     * @return reference to the current object.
     */
    bigint &operator+=(const bigint &);

    /**
     * @brief the operator -= to subtract another bigint object from the current object.
     * @param num2-> the bigint object to be subtracted to current object.
     * @return reference to the current object.
     */
    bigint &operator-=(const bigint &);
    /**
     * @brief overloads operator *= to mutlitply two bigint objects.
     * @param num2 ->is multiply with the current object.
     * @return reference to the current object.
     */
    bigint &operator*=(const bigint &);

    /**
     * @brief  Prints the bigint objects to an output stream.
     * @param out is the output stream.
     */
    void print(std::ostream &out) const;
    /**
     * @brief  The overload operator less than (<) to compare two bigint objects.
     * @param num2 -> Compare the current object with num2 bigint object.
     * @return true if the current object is less than num2.
     * @return false otherwise.
     */
    bool operator<(const bigint &num2) const;

    /**
     * @brief The overload operator greater than (>) to compare tow bigint objects
     * @param num2-> Compare the current object with num2 bigint object.
     * @return true if the current object is greater than num2
     * @return false otherwise.
     */
    bool operator>(const bigint &num2) const;
    /**
     * @brief overload operator greater than  or equal (>=) to compare tow bigint objects
     *
     * @param num2-> Compare the current object with num2 bigint object.
     * @return true  if the current object is greater than  or equal to num2.
     * @return false otherwise.
     */
    bool operator>=(const bigint &num2) const;
    /**
     * @brief overload operator less than  or equal (<=) to compare tow bigint objects
     *
     * @param num2-> Compare the current object with num2 bigint object.
     * @return true true  if the current object is less than  or equal to num2.
     * @return false otherwise.
     */
    bool operator<=(const bigint &num2) const;
    /**
     * @brief pre-increment operator (++num).
     * Increase the value of bigint object by one.
     * @return The reference to the current object.
     */
    bigint &operator++();

    /**
     * @brief post-increment operator (num++).
     * Also increase the value of bigint object by one but return the original value.
     * @return copy of the bigint object before incrementing it.
     */
    bigint operator++(int);
    /**
     * @brief pre-decrement operator (--num).
     * This decreases the value by  one'
     * @return the current object.
     */
    bigint &operator--();
    /**
     * @brief post-decrement operator (num--);
     * This decreases the value by one but return the original value.
     * @return Copy of the bigint object before decremnent.
     */
    bigint operator--(int);

    /**
     * @brief overload operator for the Negation(-)
     * @param input -> is the bigint object to be negated.
     * @return the bigint object with sign flip.
     */
    friend bigint operator-(const bigint &input);

    /**
     * @brief overload operator == compares two bigint object.
     * @param num1 ->first bigint object.
     * @param num2 ->second bigint object.
     * @return true if the first bigint object is equal to the second bigint object.
     * @return false otherwise.
     */
    friend bool operator==(const bigint &num1, const bigint &num2); // comparision(==)

private:
    /**
     * @brief use enum to represent the sign of the class.
     */
    enum class_sign
    {
        positive,
        Negative
    };

    class_sign numberSign;       // store sign of our class positive or negative.
    std::vector<char> numDigits; // store all the digits of bigint.

    /**
     * We have helper function that removes the leading zeros.
     */
    void remove_leading_zeros();
};

//%%%%%%%%%%%%%%%begin implementation

//%%%%% the default constructor
bigint::bigint() : numberSign(positive), numDigits(1, '0') {}

//%%%%% the integer constructor
bigint::bigint(int64_t number)
{
    if (number < 0)
    {

        numberSign = Negative; // we set the sign to negative
        number = -1 * number;  // convert to positive
    }
    else
    {

        numberSign = positive; // set the sign to positve
    }
    do
    {
        numDigits.push_back('0' + (number % 10));

        number = number / 10; // remove the last digit
    } while (number > 0);
}

//%%%%%%%% the string constructor
bigint::bigint(const std::string &str)
{
    if (str.empty())
        throw std::invalid_argument("Error:if the string is empty");
    size_t s = 0;
    if (str[0] == '-')
    {
        numberSign = Negative; // setting sign to negative
        s = 1;                 // we skip the negative sign - and start processing the digits
    }
    else
    {
        numberSign = positive;
        if (str[0] == '+')
            s = 1; // skip the + and start processing the digits.
    }
    //%%%%%  we process the sting digits of the number in reverse order
    for (size_t m = str.size(); m > s; --m)
    {
        if (!isdigit(str[m - 1]))
            throw std::invalid_argument(" invalid character");
        numDigits.push_back(str[m - 1]); // store digits in reverse order
    }
    remove_leading_zeros();
}

//%%%%%%% helper function for removing leading zeros
void bigint::remove_leading_zeros()
{
    while (numDigits.size() > 1 && numDigits.back() == '0')
    {
        numDigits.pop_back();
    }
    if (numDigits.size() == 1 && numDigits[0] == '0')
        numberSign = positive; // set sign to positive
}

//%%%%%%%%%%%%%%%%%%% implementation of the operator +=
bigint &bigint::operator+=(const bigint &num2)
{
    // if we have the same sign we add the numbers.
    if (numberSign == num2.numberSign)
    {
        size_t max_length = std::max(numDigits.size(), num2.numDigits.size());
        numDigits.resize(max_length, '0');

        int64_t carry = 0; // intialize  carry
        for (size_t m = 0; m < max_length || carry; ++m)
        {
            int64_t total = (m < numDigits.size() ? numDigits[m] - '0' : 0) + (m < num2.numDigits.size() ? num2.numDigits[m] - '0' : 0) + carry;
            if (m >= numDigits.size())
                numDigits.push_back('0');
            numDigits[m] = '0' + (total % 10);
            carry = total / 10; //  update carry
        }
    }
    else
    {
        //%%% different sign implemented here
        bigint bigger_one = *this;
        bigint smaller_one = num2;
        //
        bigger_one.numberSign = positive;
        smaller_one.numberSign = positive;
        if (bigger_one < smaller_one)
        {
            // we swap the bigger number and smaller number
            std::swap(bigger_one, smaller_one);
            numberSign = num2.numberSign;
        }

        numDigits.resize(bigger_one.numDigits.size(), '0'); // we resize
        int64_t borrow = 0;                                 // initialize borrow to zero
        for (size_t m = 0; m < bigger_one.numDigits.size(); ++m)
        {
            int64_t difference = (m < bigger_one.numDigits.size() ? bigger_one.numDigits[m] - '0' : 0) - (m < smaller_one.numDigits.size() ? smaller_one.numDigits[m] - '0' : 0) - borrow;
            if (difference < 0)
            {
                difference += 10;
                borrow = 1;
            }
            else
                borrow = 0;
            numDigits[m] = '0' + (difference % 10); // store result
        }
        remove_leading_zeros();
    }

    return *this;
}

/**
 * @brief overload operator (+) for adding two bigint objects.
 * @param num1 -> the first bigint object.
 * @param num2 -> the seocnd bigint object.
 * @return the sum of num1 and num2.
 */
bigint operator+(const bigint &num1, const bigint &num2)
{
    bigint result; // store temporary result.
    result = num1; // copy num1 into result
    result += num2;

    return result;
}

//%%%%%%%% we use the overload operator -= we built it from the prevvious operator +=
bigint &bigint::operator-=(const bigint &num2)
{
    bigint temp = num2;
    temp.numberSign = (num2.numberSign == positive) ? Negative : positive; // flip the sign of rhs
    *this += temp;
    return *this;
}

/**
 * @brief overload operator (-) to subtract two bigint object.
 * @param num1 -> the first bigint object.
 * @param num2 -> the second bigint objec.
 * @return The differnce of num1 and num2.
 */
bigint operator-(const bigint &num1, const bigint &num2)
{
    bigint result;
    result = num1; // copy num1 into result
    result -= num2;
    return result;
}

//%%%%%%%%%%%%%%%% Implementation of the multiplication operator
bigint &bigint::operator*=(const bigint &num2)
{
    class_sign output_sign = (numberSign == num2.numberSign) ? positive : Negative; // take care of the sign
    std::vector<char> output(numDigits.size() + num2.numDigits.size(), '0');        // we initialze the output vector
    for (size_t m = 0; m < numDigits.size(); ++m)

    { // multiplying each digits
        int64_t carry = 0;
        for (size_t n = 0; n < num2.numDigits.size() || carry; ++n)
        {
            int64_t numDigits_product = (output[m + n] - '0') + (numDigits[m] - '0') * (n < num2.numDigits.size() ? num2.numDigits[n] - '0' : 0) + carry;
            output[m + n] = '0' + (numDigits_product % 10);
            carry = numDigits_product / 10;
        }
    }

    numDigits = output;
    numberSign = output_sign;
    remove_leading_zeros(); // remove leading zeros
    return *this;
}

/**
 * @brief overload operator (*) for multiplying tow bigint object.
 * @param num1 -> the first bigint object.
 * @param num2 -> the second bigint object.
 * @return the product of num1 and num2.
 */
bigint operator*(const bigint &num1, const bigint &num2)
{
    bigint result;
    result = num1; // copy num1 into result
    result *= num2;
    return result;
}

//%%%%%%%%%% the Negation operator
bigint operator-(const bigint &input)
{
    bigint temp = input;
    if (temp.numDigits.size() != 1 || temp.numDigits[0] != '0')
    {
        temp.numberSign = (input.numberSign == bigint::positive) ? bigint::Negative : bigint::positive;
    }
    return temp;
}

//%%%%%%%%%%%%%%%%% define the operator ==
bool operator==(const bigint &num1, const bigint &num2)
{
    return (num1.numberSign == num2.numberSign) && (num1.numDigits == num2.numDigits);
}
//%%%%%%% implementation of  the operator !=
bool operator!=(const bigint &num1, const bigint &num2)
{
    return !(num2 == num1);
}

///  the operator less than.
bool bigint::operator<(const bigint &num2) const
//%%%% compare sign,magnitude and digits
{
    if (numberSign != num2.numberSign)
    {
        return numberSign == Negative;
    }
    if (numDigits.size() != num2.numDigits.size())
    {
        return (numberSign == positive) ? numDigits.size() < num2.numDigits.size() : numDigits.size() > num2.numDigits.size();
    }
    for (size_t m = numDigits.size(); m-- > 0;)
    {
        if (numDigits[m] != num2.numDigits[m])
        {
            return (numberSign == positive) ? numDigits[m] < num2.numDigits[m] : numDigits[m] > num2.numDigits[m];
        }
    }
    return false;
}

//%%%%% of the operator >
bool bigint::operator>(const bigint &num2) const
{
    return num2 < *this;
}

//%%%%%%%%%%%% the operator >=
bool bigint::operator>=(const bigint &num2) const
{
    return !(*this < num2);
}

//%%%%%%%%%% the operator <=
bool bigint::operator<=(const bigint &num2) const
{
    return !(*this > num2);
}

//%%%%%%%%%%%%%% the pre-increament
bigint &bigint::operator++()
{
    return *this += bigint(1); // add one
}
//%%%%% post--increament we have
bigint bigint::operator++(int)
{
    bigint temp;
    temp = *this; // copy the current object.
    ++(*this);
    return temp;
}

//%%%%%%%%%% the pre-decrement operator
bigint &bigint::operator--()
{
    return *this -= bigint(1); // subtract one
}
//%%%  the post--decrement operator
bigint bigint::operator--(int)
{
    bigint temp;
    temp = *this; // copy current object
    --(*this);
    return temp;
}

// help to print the sign and digits of the class to an output stream
void bigint::print(std::ostream &out) const
{
    if (numberSign == Negative)
        out << '-'; // print the neagitve sign
    for (auto it = numDigits.rbegin(); it != numDigits.rend(); ++it)
        out << *it;
}
//%%%%%%%%%%%%%%  the Insertion << operator to print output
inline std::ostream &operator<<(std::ostream &out, const bigint &value)
{
    value.print(out);
    return out;
}
