#include <iostream>
#include<string>

int main(){
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int K;
    std::cin >> K;

    for(int i = 0; S[i] != '\0'; i++){
        if(S[i] != S[K-1]){
            S[i] = '*';
        }
    }

    std::cout << S;
}