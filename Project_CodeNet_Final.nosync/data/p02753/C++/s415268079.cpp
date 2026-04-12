#include <iostream>

int main(){
    std::string s;
    std::cin >> s;

    if(s.at(0) != s.at(1) || s.at(1) != s.at(2) || s.at(2) != s.at(0)){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }

    return 0;
}