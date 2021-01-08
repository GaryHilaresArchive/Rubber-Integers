# GIntegers
GIntegers: Arbitrary Integer Size support for C++.
## Setup
1. Download the project from GitHub or clone the repository using the following command:
```
git clone https://github.com/GaryNLOL/GIntegers.git
```
2. Add the include files to your project's folder or to your compiler's search path.
3. Add the following line to your `.cpp` file:
- If you added it to your project's folder:
```
#include "include/GIntegers/GIntegers.hpp"
```
- If you added it to your compiler's path:
```
#include <GIntegers/GIntegers.hpp>
```
4. You're ready to start using GIntegers!

## Structure
### GIntegers (namespace)
#### GInt (class)
##### Public methods
`GInt()` -> Creates a `GInt` default initialized to 0.

`GInt(const std::string& newVal)` -> Creates a `GInt` from a `std::string`.

`template<typename int_type, typename = typename std::enable_if<std::is_integral<int_type>::value>::type> GInt(const int_type newVal)` -> Creates a `GInt` from any type of integer: `int`, `long int`, `long long int`, `unsigned long long int`, `size_t`, etc.

`std::string to_string() const` -> `Returns the object's value in the form of a `std::string`.

`friend std::ostream& operator<<(std::ostream& stream, const GInt& num)` -> Sends the value of `num` to the output stream `stream`.

`friend std::istream& operator>>(std::istream& stream, GInt& num)` -> Sets the value of `num` to the input value from `stream`.

`bool operator==(const GInt& num2) const` -> Returns true if the object's value and `num2`'s value are equal. Returns false otherwise.

`bool operator!=(const GInt& num2) const` -> Returns true if the object's value and `num2`'s value are different. Returns false otherwise.

`bool operator>(const GInt& num2) const` -> Returns true if the object's value is higher than `num2`'s value. Returns false otherwise.

`bool operator<=(const GInt& num2) const` -> Returns true if the object's value is lower or equal to `num2`'s value. Returns false otherwise.

`bool operator>=(const GInt& num2) const` -> Returns true if the object's value is higher or equal to `num2`'s value. Returns false otherwise.

`bool operator<(const GInt& num2) const` -> Returns true if the object's value is lower than `num2`'s value. Returns false otherwise.

`GInt operator+(const GInt& num2) const` -> Returns the value of the object plus `num2`.

`GInt operator-(const GInt& num2) const` -> Returns the value of the object minus `num2`.

`GInt operator+=(const GInt& num2)` -> Sets the object's value to itself plus `num2` and returns the new object's value.

`GInt operator-=(const GInt& num2)` -> Sets the object's value to itself minus `num2` and returns the new object's value.

`GInt operator++()` -> Sets the object's value to itself plus 1 and returns the old object's value.

`GInt operator++(int)` -> Sets the object's value to itself plus 1 and returns the new object's value.

`GInt operator--()` -> Sets the object's value to itself minus 1 and returns the old object's value.

`GInt operator--(int)` -> Sets the object's value to itself minus 1 and returns the new object's value.

`GInt operator*(const GInt& num2) const` -> Returns the value of the object multiplied by `num2`.

`GInt operator*=(const GInt& num2)` -> Sets the object's value to itself multiplied by `num2` and returns the new object's value.

`GInt operator/(const GInt& num2) const` -> Returns the value of the object divided by `num2`.

`GInt operator/=(const GInt& num2)` -> Sets the object's value to itself divided by `num2` and returns the new object's value.

`GInt operator%(const GInt& num2) const` -> Returns the value of the object module `num2`.

`GInt operator%=(const GInt& num2)` -> Sets the object's value to itself module `num2` and returns the new object's value.

`GInt factorial()` -> Returns a GInt with the object's factorial.

`GInt abs() const` -> Returns a GInt with the object's absolute value.
