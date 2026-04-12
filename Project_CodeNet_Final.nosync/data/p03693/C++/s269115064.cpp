#include <iostream>
#include <string>

int main() {
    std::string s;
    for (int i=0; i<3; ++i) {
        char tmp;
        std::cin >> tmp;
        s += tmp;
    }
    if (std::stoi(s) % 4 == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}