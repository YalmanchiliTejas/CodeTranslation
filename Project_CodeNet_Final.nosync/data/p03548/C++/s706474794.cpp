#include <iostream>

int main() {
    unsigned int X;
    unsigned int Y;
    unsigned int Z;

    std::cin >> X;
    std::cin >> Y;
    std::cin >> Z;

    X = X - Z;
    Y = Y + Z;

    std::cout << X / Y;

    return 0;
}