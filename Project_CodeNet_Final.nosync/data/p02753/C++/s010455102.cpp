#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <limits>
#include <set>
#include <map>

int main()
{
    std::string s;
    std::cin >> s;
    if (s[0] == s[1] && s[1] == s[2]) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }

    return 0;
}