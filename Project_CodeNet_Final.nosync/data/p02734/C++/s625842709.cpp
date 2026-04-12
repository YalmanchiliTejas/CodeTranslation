#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll dp[3001][6001][3];
constexpr long long MOD = 998244353;
int main() {
    int n, s;
    cin >> n >> s;
    vector<ll> A(n);
    for(auto &x : A) {
        cin >> x;
    }
    dp[0][0][0] = 1;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j <= s; j++) {

            (dp[i + 1][j][0] += dp[i][j][0]) %= MOD;
            (dp[i + 1][j + A[i]][1] += dp[i][j][0] * (i + 1)) %= MOD;
            (dp[i + 1][j + A[i]][2] += dp[i][j][0] * (i + 1) * (n - i)) %= MOD;

            (dp[i + 1][j][1] += dp[i][j][1]) %= MOD;
            (dp[i + 1][j + A[i]][1] += dp[i][j][1]) %= MOD;
            (dp[i + 1][A[i] + j][2] += dp[i][j][1] * (n - i)) %= MOD;

            (dp[i + 1][j][2] += dp[i][j][2]) %= MOD;
        }
    }
    cout << dp[n][s][2] << endl;
}