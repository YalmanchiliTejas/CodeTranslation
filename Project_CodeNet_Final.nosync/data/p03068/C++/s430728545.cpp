#include <iostream>
#include<string>

using namespace std;

int main(void){
    
    unsigned int N, K;
    string S;
    std::cin >> N >> S >> K;
    
    for(int i=0; i<N; i++){
        if(S[i]!=S[K-1]){
            S[i] = '*';
        }
    }
    
    std::cout << S << std::endl;
    return 0;
}
