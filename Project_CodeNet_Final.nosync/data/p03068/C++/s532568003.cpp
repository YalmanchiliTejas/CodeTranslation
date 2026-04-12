#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> S >> K;
    
    string T = "";
    for (int i = 0; i < N; i++) {
        if(S[i] == S[K - 1]) T += S[i];
        else T += "*";
    }
    
    cout << T << endl;
}