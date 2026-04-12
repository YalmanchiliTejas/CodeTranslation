#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int x = n * 800;
    int y = n / 15 * 200;

    std::cout << x - y << std::endl;
}
