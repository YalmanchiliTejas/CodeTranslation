#include <stdio.h>
#include <iostream>
#include <string>

int main(void) {
    std::string s;

    std::cin >> s;

    if(s.compare("AAA") == 0 || s.compare("BBB") == 0){
        std::cout << "No" << std::endl;
    }else{
        std::cout << "Yes" << std::endl;
    }
}
