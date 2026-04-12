#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;

    if (s == "AAA" || s == "BBB")
    {
        std::cout << "No";
    }
    else
    {
        std::cout << "Yes";
    }
}
