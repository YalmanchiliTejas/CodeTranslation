#include <iostream>

int main(void) {
    int n, m;

    std::cin >> n >> m;

    if (n == m) {
        std::cout << "a == b" << std::endl;
    } else if (m < n) {
        std::cout << "a > b" << std::endl;
    } else {
        std::cout << "a < b" << std::endl;
    }

    return 0;
}