#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char *argv[])
{
    int x;

    std::cin >> x;

    if (x >= 30) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
