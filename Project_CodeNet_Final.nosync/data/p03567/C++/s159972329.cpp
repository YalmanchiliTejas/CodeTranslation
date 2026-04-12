#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.length() - 1; i++) {
        if (s.substr(i, 2) == "AC") {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    std::cout << "No" << std::endl;
}
