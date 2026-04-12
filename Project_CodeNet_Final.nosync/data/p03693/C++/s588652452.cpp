#include <iostream>

int main() {
    int r, g, b;
    std::cin >> r >> g >> b;

    int num = b + (10 * g) + (100 * r);
    if (num % 4) {
        std::cout << "NO\n";
    } else {
         std::cout << "YES\n";
    }

}