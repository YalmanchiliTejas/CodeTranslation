#include<iostream>

int main(void){
    std::string s;
    std::cin >> s;
    if(s[0] == 'A' && s[1] == 'A' && s[2] == 'A'){
	std::cout << "No" << std::endl;
    }else if(s[0] == 'B' && s[1] == 'B' && s[2] == 'B'){
	std::cout << "No" << std::endl;
    }else{
	std::cout << "Yes" << std::endl;
    }
    return 0;
}

