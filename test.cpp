#include "bigint.hpp"
#include <exception>
#include <stdexcept>
#include <vector>
int main()
{
    try
    {
        //%%%%%%%%%%%%%%%%%% default constructor
        // bigint x;
        // std::cout << "x(default constructor):" << x << '\n';

        //%%%%%%%%%%%%%% constructor with int64bit
        // bigint y(99);
        // bigint q(1);
        // std::cout << " y(int64_t constructor):" << y << '\n';
        // y += q;
        // std::cout << "y+=q(99+1):" << y << '\n';
        // bigint z(-22496);
        // std::cout << "z(Negative int64_t construcotor ):" << z << '\n';

        //%%%%%%%%%%%%%%%%% string constructor
        // bigint r("54321");
        // std::cout << "r(string Constructor):" << r << '\n';
        // bigint t("-12345");
        // std::cout << "t(sting with negative argument):" << t << '\n';

        //%%%%%%%%% test the operator +=
        // bigint v("100");
        // bigint w("1");
        // v += w;
        // std::cout << "v+=w(99+1):" << v << '\n';
        // case of negative
        // bigint b("-500");
        // bigint a("-500");
        // b += a;
        // std::cout << "z+=a(-500-500):" << b << '\n';

        //%%%%%%%%%% testing the operator +
        // bigint A(-60);
        // bigint B(-40);
        // bigint C = A + B;
        // std::cout << "add(60+40):=" << C << '\n';
        // bigint W("700");
        // bigint X("-400");
        // bigint H = W + X;
        // std::cout << "print H=(W+X):" << H << '\n';
        // bigint Q("-700");
        // bigint R("-300");
        // bigint D = Q + R;
        // std::cout << "print adding two negative: D=(Q+H)" << D << '\n';
        // HWO ABOUT A VERY large number like...
        // bigint Y("00000000000008956");
        // bigint E("089043");
        // bigint S = Y + E;
        // bigint a("00000001234500");
        // std::cout << "test for print:" << a << '\n';
        // std::cout << "print large number S=Y+E=" << S << '\n';

        //%%%%%%%%%%%%% try testing the -= operator
        // bigint a("-100000000000000000000000000000000000");
        // bigint c("-1");
        // a -= c;
        // std::cout << "result:a-c=" << a << '\n';

        //%%%%%%%%%%%%% test for - operator
        // bigint d(-500);
        // bigint m(-200);
        // bigint x = d - m;
        // std::cout << "print result:x=d-m:" << x << '\n';

        //%%%%%%% try to test the operator *=
        // bigint a("-5");
        // bigint b("-4");
        // a *= b;
        // std::cout << "the product a and b:" << a << '\n';

        //%%%%%%%%%%%%%%%%%%%%%%
        // testing the operator *
        bigint a("450986877907696509804558906689048948977569868979878956987865749856878978754");
        bigint b("43969677096976090709596679070079877796596696869");
        bigint c = a * b;
        std::cout << "product of a and b:" << c << '\n';

        //%%%%%%%%%%%%%%%%% test for the Negation
        // bigint a(-2345);
        // std::cout << "Original copy:" << a << ",Negated:" << -a << '\n';

        // %% test the implementation of ==
        // bigint a("1234");
        // bigint b("1234");
        // bigint c("-1234");
        // std::cout << "a==b:" << (a == b) << '\n';
        // std::cout << "b==c:" << (b == c) << '\n';

        //%%%%%%%%% testing not equal
        // bigint a("36577777777777777777777777777777");
        // bigint b("36577777777777777777777777777777");
        // bigint c("-36545678887778889775686786787586576");
        // std::cout << "a!=b:" << (a != b) << '\n';
        // std::cout << "a!=c:" << (a != c) << '\n';

        //%%%%% test for > operator
        // bigint d("1234558679797978798976697876978795656675");
        // bigint e("54321");
        // bigint g("-12345");
        // bigint f("-54321");
        // bigint j("12345");
        // std::cout << "d >e:" << (d > e) << '\n';
        // std::cout << "e > d:" << (e > d) << '\n';
        // std::cout << "g>f:" << (g > f) << '\n';
        // std::cout << "f>g:" << (f > g) << '\n';
        // std::cout << "d > j:" << (d > j) << '\n';

        //%%%%%%%% test <= and >=
        // bigint a("200");
        // bigint b("200");
        // bigint c(200);
        // bigint d("300");
        // std::cout << "a is less than or equal to b:" << (a <= b) << '\n';
        // std::cout << "b is greater than or equal to c:" << (b >= c) << '\n';
        // std::cout << "c is less than or equal d:" << (c >= d) << '\n';

        //%%%%%%%%%%% test pre and post increment
        // bigint a("23");
        // std::cout << "the value:" << a << '\n';
        // std::cout << "pre-increament:" << ++a << '\n';
        // std::cout << "post-increment:" << a++ << '\n';
        // bigint b(0);
        // std::cout << "post--increment:" << b++ << '\n';
        // std::cout << "result after post increment;" << b << '\n';

        //%%%%%%% test pre and post decrement
        // bigint a("25");
        // std::cout << "the value:" << a << '\n';
        // std::cout << "pre-decrement:" << --a << '\n';
        // std::cout << "post-increment:" << a++ << '\n';
        // bigint b("20");
        // std::cout<<"actual value b:"<<b<<'\n';
        // std::cout << "post-decrement:" << b-- << '\n';
        // std::cout << "result after post decrement;" << b << '\n';
    }
    catch (const std::exception &e) //%%%% copied from the lecture notes
    {

        std::cout << "Error: " << e.what() << '\n';
    }
}
