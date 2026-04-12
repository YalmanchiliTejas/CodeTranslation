#include "stdio.h"
#include <iostream>

int main()
{
    int x;
    std::cin >> x;

    if (x >= 30)
    {
        std::cout << "Yes";
        return 0;
    }
    std::cout << "No";
    return 0;
}