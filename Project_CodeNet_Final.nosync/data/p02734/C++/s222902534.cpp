#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, i, j, s;
    cin >> n >> s;
    vector<ll> A(n);
    for(auto &x : A) cin >> x;
    vector<vector<ll>> dp(n + 1, vector<ll>(6001, 0));
    dp[0][0] = 1;
    for(i = 0; i < n; i++) {
        for(j = 0; j <= s; j++) {
            (dp[i + 1][j + A[i]] += dp[i][j]) %= MOD;
            (dp[i + 1][j] += dp[i][j]) %= MOD;
        }
        dp[i + 1][0] = i + 2;
    }
    ll ret = 0;
    for(i = 0; i < n; i++) (ret += dp[i + 1][s]) %= MOD;
    cout << ret << endl;
    return 0;
}
