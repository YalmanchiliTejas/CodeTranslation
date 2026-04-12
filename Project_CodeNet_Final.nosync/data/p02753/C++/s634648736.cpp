#include <iostream>

int main() {
    std::string s, t;
    std::cin >> s >> t;
    std::cout << (s == "AAA" or s == "BBB" ? "No" : "Yes") << std::endl;
}