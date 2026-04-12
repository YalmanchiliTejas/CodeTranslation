#include <bits/stdc++.h>
using namespace std;

int main(){
    
    
    int N,K;
    string S;
    
    cin >> N;
    cin >> S;
    cin >> K;
    
    char w = S[K-1];
    
    for(int i=0; i<N; i++){
        if(S[i] != w){
            S[i] = '*';
        }
    }
    
    cout << S << endl;
    
    return 0;
    
}