#include <iostream>

int main(){
    std::string s;
    std::cin >> s;

    for(int i = 0; i < s.size() - 1; ++i){
        if("AC" == s.substr(i, 2)){
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }

    std::cout << "No" << std::endl;
    return 0;
}