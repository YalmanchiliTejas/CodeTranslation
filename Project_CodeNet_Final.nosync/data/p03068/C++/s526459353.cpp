#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N, K;
    string S;

    cin >> N >> S >> K;
    for (int i = 0; i < S.length(); i++) {
        S[i] = S[i] != S[K - 1] ? '*' : S[i];
    }
    cout << S << endl;
    return 0;
}