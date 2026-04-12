#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int N, K;
    string S;
    cin >> N >> S >> K;
    
    char c;
    c = S[K - 1];
    
    for(int i = 0; i < S.length(); i++){
        if(S[i] != c){
            S[i] = '*';
        }
    }
    
    cout << S;
}