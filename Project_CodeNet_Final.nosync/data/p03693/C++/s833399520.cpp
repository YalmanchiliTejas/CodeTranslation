#include <iostream>

int main() {
    int r, g, b;
    std::cin >> r >> g >> b;

    int sum = (r * 100) + (g * 10) + b;

    if(sum % 4 == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}