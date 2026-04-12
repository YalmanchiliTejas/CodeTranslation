#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll M = 1e9+7;

// calc x
// ax %% 1 (mod M)
ll inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}

int main() {
    ll N, D, X;
    while(cin >> N >> D >> X, N) {
        vector<vector<ll>> dp(N+1, vector<ll>(N+1));
        dp[0][0] = 1;
        vector<vector<ll>> dp_sum(N+1, vector<ll>(N+1));
        fill(dp_sum[0].begin(), dp_sum[0].end(), 1);
        for(int i=1; i<=N; ++i) {
            for(int j=i; j<=N; ++j) {
                if(j-X >= 0) {
                    dp[i][j] = (dp_sum[i-1][j-1] - dp_sum[i-1][j-X] + M) % M;
                } else {
                    dp[i][j] = dp_sum[i-1][j-1];
                }
            }
            for(int j=1; j<=N; ++j) {
                dp_sum[i][j] = (dp_sum[i][j-1] + dp[i][j]) % M;
            }
        }
        ll res = 0;
        ll cmb = 1;
        for(int i=1; i<=min(N, D); ++i) {
            cmb = (cmb * ((D-i+1) % M)) % M;
            cmb = (cmb * inv(i, M)) % M;
            res = (res + dp[i][N] * cmb) % M;
        }
        cout << res << endl;
    }
}
