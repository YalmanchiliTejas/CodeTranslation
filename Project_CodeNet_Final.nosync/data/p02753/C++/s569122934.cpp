#include <iostream>
#include <string>

std::string S;

int main() {
    std::cin >> S;
    if ((S.find("A") == std::string::npos) or (S.find("B") == std::string::npos)) {
        std::cout << "No";
    } else {
        std::cout << "Yes";
    }
}