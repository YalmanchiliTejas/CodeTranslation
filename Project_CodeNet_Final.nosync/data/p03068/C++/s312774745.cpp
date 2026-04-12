#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
    int N, K;
    string S;
    cin >> N >> S >> K;
    char s = S[K - 1];
    rep(i, N) {
        if (S[i] == s) cout << S[i];
        else cout << '*';
    }
    return 0;
}