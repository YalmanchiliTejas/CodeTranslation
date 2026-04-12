#pragma gcc optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string k; cin >> k;
    int d; cin >> d;
    vector<vector<vector<int>>> dp(k.size(), vector<vector<int>>(2, vector<int>(d, -1)));
    function<int(int, int, int)> solve = [&] (int p, int lim, int rem) {
        if (p >= k.size()) return int(!rem);
        if (dp[p][lim][rem] != -1) return dp[p][lim][rem];
        int cnt = 0;
        for (int i = 0; i <= (lim ? k[p] - '0': 9); ++i)
            (cnt += solve(p + 1, lim ? k[p] - '0' == i : 0, (rem + i) % d)) %= MOD;
        return dp[p][lim][rem] = cnt;
    };
    cout << (solve(0, 1, 0) + MOD - 1) % MOD << '\n';
}