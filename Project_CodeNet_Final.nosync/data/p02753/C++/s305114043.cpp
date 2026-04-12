#include<iostream>
#include<string>

int main(){
        std::string S;
        std::cin >> S;
        if(S[0] != S[1] || S[1] != S[2])
                std::cout << "Yes";
        else
                std::cout << "No";
        return 0;
}