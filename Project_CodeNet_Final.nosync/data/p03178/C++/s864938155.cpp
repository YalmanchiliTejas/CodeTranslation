#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

int main() {
    string k; cin >> k;
    int d; cin >> d;
    const int n = k.size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(d, vector<int>(2)));
    dp[0][0][0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < d; ++j) {
            for(int lt = 0; lt < 2; ++lt) {
                for(int nxt = 0; nxt <= (lt == 0 ? (k[i] - '0') : 9); ++nxt) {
                    const int nlt = lt | (nxt < (k[i] - '0'));
                    (dp[i + 1][(j + nxt) % d][nlt] += dp[i][j][lt]) %= mod;
                }
            }
        }
    }

    int ans = (dp[n][0][0] + dp[n][0][1]) % mod;
    (ans += mod - 1) %= mod;
    cout << ans << endl;
}
