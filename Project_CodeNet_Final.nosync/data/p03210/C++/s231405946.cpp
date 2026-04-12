#include <iostream>

int main() {
    int X;
    std::cin >> X;
    
    if (X==5 || X==7 || X==3)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
}