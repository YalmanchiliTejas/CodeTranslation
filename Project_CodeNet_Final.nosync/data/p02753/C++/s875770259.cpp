#include<iostream>
#include<string>

int main(){
    std::string S;
    std::cin >> S;
    for(int i = 1; i < 3; i++){
        if(S[0] != S[i]){
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    std::cout << "No" << std::endl;
    return 0;
}
