#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, K;
    string S;
    cin >> N >> S >> K;
    for (int64_t i = 0; i < N; i++) {
        if (S[i] != S[K - 1]) {
            S[i] = '*';
        }
    }

    cout << S << endl;
}