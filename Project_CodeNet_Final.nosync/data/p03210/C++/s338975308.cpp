#include <iostream>

int main() {
    int x;
    std::cin >> x;

    if(x == 3 or x == 5 or x == 7) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
