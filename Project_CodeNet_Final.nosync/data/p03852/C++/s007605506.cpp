#include <iostream>

int main()
{
    char c;
    std::cin >> c;

    std::string s = "aeiou";

    for (auto e : s) {
        if (e == c) {
            std::cout << "vowel" << std::endl;
            return 0;
        }
    }
    std::cout << "consonant" << std::endl;
}
