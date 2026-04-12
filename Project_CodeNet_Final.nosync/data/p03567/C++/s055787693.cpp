#include <iostream>
#include <string>

int main(){
    std::string input;
    std::cin >> input;
    bool flag = false;
    bool result = false;
    for(int i = 0; i < input.size(); ++i){
        char hoge = input[i];
        if(flag){
            if(hoge == 'C'){
                result = true; 
                break;
            }
        }
        flag = false;
        if(hoge == 'A') flag = true;
    }
    if(result){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
}