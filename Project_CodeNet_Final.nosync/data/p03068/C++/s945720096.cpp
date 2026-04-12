#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = (int)1e9 + 7;
int INF = (int)2e18;
// Comment out below and program paste

// #include "UnionFind.hpp"
// #include "power.hpp"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    string S;
    cin >> N >> S >> K;
    char check = S[K - 1];
    for (int i = 0; i < S.length(); i++) {
        if (S[i] != check) S[i] = '*';
    }
    cout << S << endl;
}
