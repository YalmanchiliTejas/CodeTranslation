#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    string S;
    cin >> N >> S >> K;
    for (int i = 0; i < S.size(); ++i) {
        if(S[i] != S[K-1]) S[i] = '*';
    }
    cout << S;
    return 0;
}