# Porject title: bigint class.


## Overview
In this project we implemented bigint class for arbitrary precision integers using C++.

## Features
* The following constructors are implemented: default constructor, constructor that takes signed 64-bit integer and constructor that takes string of digits and convert it to an arbitrary-precision integer.
* Overloaded operators: +=, +, -=, -,*=,*, <, >, <=, >=, ==, !=, <<, ++, --, and negation (-).
* Handle large integers both Negative and positive.
* Also handle error for invalid input.


## Example the operator *
```cpp
bigint a("450986877907696509804558906689048948977569868979878956987865749856878978754");
bigint b("43969677096976090709596679070079877796596696869");
bigint c = a * b;
std::cout << "product of a and b:" << c << '\n';//output: 19829747396574795730948367549568425857958025553818652499112849798476142718119109997672646491207586450973537230918429321226

Author: Samba Dumbuya
