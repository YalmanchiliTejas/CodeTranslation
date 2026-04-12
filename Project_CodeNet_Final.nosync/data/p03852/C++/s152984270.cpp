#include <iostream>

int main() {
    std::string a, res;
    std::cin >> a;

    if (a.find('a') != std::string::npos ||
        a.find('i') != std::string::npos ||
        a.find('u') != std::string::npos ||
        a.find('e') != std::string::npos ||
        a.find('o') != std::string::npos)           {
        res = "vowel";
    } else {
        res = "consonant";
    }

    std::cout << res << std::endl;
    return 0;
}