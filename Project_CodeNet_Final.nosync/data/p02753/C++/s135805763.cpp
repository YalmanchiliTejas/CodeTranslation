#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    long n;
    std::string s;

    std::cin >> s;
    std::cout << ((s[0] == s[1] && s[1] == s[2]) ? "No" : "Yes") << std::endl;
}