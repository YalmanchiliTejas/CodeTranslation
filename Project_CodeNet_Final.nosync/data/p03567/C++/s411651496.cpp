#include <iostream>
#include <vector>

int main(void)
{
    std::string str;
    std::cin >> str;

    std::string::size_type pos = str.find("AC");
    std::cout<< (pos==std::string::npos ? "No" : "Yes") << std::endl;
    return 0;
}
