#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int N;
    char S[11];
    int K;

    //input
    cin >> N;
    cin >> S;
    cin >> K;

    for(int i = 0; i < N; i++){
        if(S[i] != S[K-1]){
            S[i] = '*';
        }
    }

    //output
    cout << S << endl;

    return 0;
}
