#include <iostream>

int main() {
    int r, g, b; std::cin >> r >> g >> b;
    std::cout << (((r * 100 + g * 10 + b) % 4 == 0)?"YES":"NO") << std::endl;
    return 0;
}