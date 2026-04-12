#include <iostream>
#include <string>

int main()
{
    std::string s, result = "No";
    std::cin>>s;
    char x = s[0];
    if(s[1] != x || s[2] != x) result = "Yes";
    std::cout<<result;
}
