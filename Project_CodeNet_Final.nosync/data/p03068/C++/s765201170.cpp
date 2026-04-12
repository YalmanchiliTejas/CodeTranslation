#include <bits/stdc++.h>
#include <cstdio>
using namespace std;



int main() {
    int N, K;
    char S[20];
    cin >> N;
    cin >> S;
    cin >> K;

    char sk = S[K-1];
    for(int i = 0; i < N; i++) {
        if (S[i] != sk) {
            S[i] = '*';
        }
    }
    cout << S << "\n";

    
}
