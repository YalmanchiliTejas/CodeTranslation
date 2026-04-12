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
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    int max_value = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        max_value = max(max_value, H[i]);
        if (max_value <= H[i]) ++ans;
    }
    cout << ans << endl;
}
