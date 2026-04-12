#include <iostream>
using namespace std;
int main(void){
    string S;
    int N,K;
    cin >> N;
    cin >> S;
    cin >> K;
    for(int i = 0; i < N; i++){
        if(S[i] != S[K-1]){
            S[i] = '*';
        }
    }
    cout << S << endl;
}