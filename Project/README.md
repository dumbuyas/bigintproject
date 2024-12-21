# Porject title: bigint class.


## Overview
In this project we implemented bigint class for arbitrary precision integers using C++.

## Features
* The following constructors are implemented: default constructor, constructor that takes signed 64-bit integer and constructor that takes string of digits and convert it to an arbitrary-precision integer.
* Overloaded operators: +=, +, -=, -,*=,*, <, >, <=, >=, ==, !=, <<, ++, --, and negation (-).
* Handle large integers both Negative and positive.
* The digits of the numbers are store in reverse order in std::vector<char> to facilitate  arithmetic operations.
* We use 'enum' to store the sign of the number (positive or negative).
* Also handle error for invalid input.
* For addition we add digits starting from the least significant to the most signifcant, since we want digits from 0 to 9, so whenever the sum is greater or equal to 10 we handle the carry.
* For subtraction we subtract the smaller magnitude from larger magnitude and adjust result based on the sign of the operand.
* For Multiplication we multiply digits individually while accounting for positional shift.



## Example the operator *


```cpp
// %% test the implementation of ==
        bigint a("1234");
        bigint b("1234");
        bigint c("-1234");
        std::cout << "a==b:" << (a == b) << '\n'; //return 1 meaning true becuase a==b.
        std::cout << "b==c:" << (b == c) << '\n'; //return 0 meaning false becuase b!=c.



 //%%%%%%%%%%%%%%%%% test for the Negation
        bigint a(-2345);
        std::cout << "Original copy:" << a << ",Negated:" << -a << '\n';  //output 2345


 //%%%%%%%%% test the operator +=
         bigint v("100");
         bigint w("1");
         v += w;
         std::cout << "v+=w(99+1):" << v << '\n'; // output= 101
//%%%%%%%%%%%%% try testing the -= operator
        bigint a("-100");
        bigint c("-1");
        a -= c;
        std::cout << "result:a-c=" << a << '\n';  //result= -99
 //%%%%%%%%%%%%% test for - operator
        bigint d(681);
        bigint m(79);
        bigint x = d - m;
        std::cout << "print result:x=d-m:" << x << '\n';  //result=602

//%%%%
bigint a("450986877907696509804558906689048948977569868979878956987865749856878978754");
bigint b("43969677096976090709596679070079877796596696869");
bigint c = a * b;
std::cout << "product of a and b:" << c << '\n';//output: 19829747396574795730948367549568425857958025553818652499112849798476142718119109997672646491207586450973537230918429321226.



author Samba Dumbuya