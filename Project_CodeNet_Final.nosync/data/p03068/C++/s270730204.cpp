#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){

    int N;
    string S;
    int K;
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