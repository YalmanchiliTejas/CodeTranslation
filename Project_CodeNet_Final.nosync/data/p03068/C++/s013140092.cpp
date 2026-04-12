#include<iostream>
#include<math.h>
#include<string>
#include<vector>
using namespace std;

int main(){
    int N,K;
    string S,T;
    cin >> N >> S >> K;
    T.resize(S.size());
    char c = S[K-1];
    for(int i = 0; i < N; i++){
        if(S[i] != c){
            T[i] = '*';
        }else{
            T[i] = S[i];
        }
    }
    cout << T << endl;
    return 0;
}