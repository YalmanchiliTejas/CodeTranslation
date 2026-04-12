#include <iostream>
#include <string>

int main() 
{
    std::string line;
    std::getline(std::cin, line);
    if (line == std::string("AAA") || line == std::string("BBB")) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }
    return 0;
}
