#include <iostream>
#include <string>
using namespace std;
int main(void){
    int N, K;
    string S;
    cin >> N >> S >> K;
    char X = S[K - 1];
    for(int i = 0; i < N; i++){
        if(S[i] != X){
            S[i] = '*';
        }
    }
    cout << S << endl;
    return 0;
}