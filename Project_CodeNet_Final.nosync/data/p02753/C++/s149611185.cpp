#include <iostream>
#include <string>

int main()
{
    std::string in;
    std::cin >> in;

    bool existA = false;
    bool existB = false;
    for (const auto& ch : in)
    {
        if (ch == 'A')
        {
            existA = true;
        }
        else if (ch == 'B')
        {
            existB = true;
        }
    }

    if (existA && existB)
    {
        std::cout << "Yes";
    }
    else
    {
        std::cout << "No";
    }
    return 0;
}