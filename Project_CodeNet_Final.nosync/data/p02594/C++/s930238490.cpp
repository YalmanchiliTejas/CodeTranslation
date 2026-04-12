#include <iostream>

int main()
{
    int temperature = 0;
    std::cin >> temperature;
    if (temperature >= 30)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
}
