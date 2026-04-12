#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    int bonus = n / 15;
    std::cout << (n * 800 - bonus * 200) << std::endl;
    return 0;
}
