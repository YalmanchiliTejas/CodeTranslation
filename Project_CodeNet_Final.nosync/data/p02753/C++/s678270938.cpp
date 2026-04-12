#include <iostream>
#include <cstdint>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main(void)
{
    std::string S;

    std::cin >> S;

    std::cout << (S.at(0) == S.at(1) && S.at(1) == S.at(2) ? "No" : "Yes") << std::endl;

    return 0;
}