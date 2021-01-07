#include "GIntegers.hpp"
#include <iostream>

int main()
{
    using namespace GIntegers;
    std::cout << "Convertible from int's and std::string's!" << std::endl;
    std::cout << "Does not pollute the global namespace! (The class is inside it's own namespace)." << std::endl;

    GInt num1(ULONG_LONG_MAX);
    num1++;
    std::cout << "Higher than ULONG_LONG_MAX!" << std::endl;
    std::cout << "num1 = " << num1 << std::endl;
    std::cout << std::endl;

    GInt num2 = num1 * -1 - 100;
    std::cout << "Lower than -1 * ULONG_LONG_MIN!" << std::endl;
    std::cout << "num2 = " << num2 << std::endl;
    std::cout << std::endl;

    GInt num3 = num1 + num2;
    std::cout << "Supports sums..." << std::endl;
    std::cout << "num3 = num2 + num1 = " << num3 << std::endl;
    std::cout << std::endl;

    GInt num4 = num3 - num2;
    std::cout << "Substractions..." << std::endl;
    std::cout << "num4 = num3 - num2 = num1 = " << num4 << std::endl;
    std::cout << std::endl;

    GInt num5 = 6453 * 6758;
    std::cout << "Multiplications" << std::endl;
    std::cout << "num5 = 6453 * 6758 = " << num5 << std::endl;
    std::cout << std::endl;

    GInt num6 = GInt("477978547397979") / 14546;
    std::cout << "Divisions!" << std::endl;
    std::cout << "num6 = 477978547397979 / 14546 = " << num6 << std::endl;
    std::cout << std::endl;

    GInt num7 = GInt("477978547397979") % 14546;
    std::cout << "Modulus!!" << std::endl;
    std::cout << "num7 = 477978547397979 % 14546 = " << num6 << std::endl;
    std::cout << std::endl;

    GInt num8 = GInt(69).factorial();
    std::cout << "Factorial!!!" << std::endl;
    std::cout << "num8 = 69! = " << num8 << std::endl;
    std::cout << std::endl;

    GInt num9 = GInt(INT_MIN).abs();
    GInt num10 = GInt(INT_MAX) * num9;
    GInt num11 = GInt(INT_MAX);
    std::cout << "And more!!!!!" << std::endl;
    std::cout << "num9 = | INT_MIN | = " << num9 << std::endl;
    std::cout << "num10 = num9 * INT_MAX = " << num10 << std::endl;
    std::cout << "num11 = INT_MAX, num11 <= num9 = " << (num11 <= num9 ? "True":"False") << std::endl;
    std::cout << std::endl;

    std::cout << "And even more, more, more is coming soon!" << std::endl;
    return 0;
}
