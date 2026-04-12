#include <iostream>
#include <string>

int main()
{
    std::string Str;
    std::cin >> Str;
    for (std::size_t i = 0; i < Str.size() - 1; ++i)
    {
        if (Str[i] == 'A' && Str[i + 1] == 'C')
        {
            std::puts("Yes");
            return 0;
        }
    }

    std::puts("No");

    return 0;
}