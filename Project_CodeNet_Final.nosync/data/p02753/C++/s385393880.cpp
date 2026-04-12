#include <iostream>
#include <string>

int main(){
    std::string s;
    std::cin >> s;

    if (s == "AAA" || s == "BBB")
    {
        std::cout << "No" << std::endl;
    }
    else
    {
        std::cout << "Yes" << std::endl;
    }
    
    return 0;
}