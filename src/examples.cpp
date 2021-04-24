#include "../include/RubberIntegers/RubberIntegers.hpp"
#include <iostream>

int main()
{
    using namespace RubberIntegers;
    RubberInt test1(RubberInt(45));
    test1 = test1 * RubberInt(-69);
    std::cout << test1;
}
