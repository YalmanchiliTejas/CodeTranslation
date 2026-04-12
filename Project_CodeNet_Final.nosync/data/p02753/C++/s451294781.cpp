#include <iostream>
#include <string>

bool judge(const std::string& s)
{
    if (s[0] != s[1])
    {
        return true;
    }

    if (s[1] != s[2])
    {
        return true;
    }

    return false;
}

int main()
{
    std::string s;
    std::cin >> s;

    std::cout << (judge(s) ? "Yes" : "No") << std::endl;

    return 0;
}
