#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

const ll MOD = 998244353;

int main(){
    int n, s; cin >> n >> s;
    vector<ll> a(n); rep(i,n) cin >> a[i];

    vector<vector<ll>> dp(n+1,vector<ll>(s+1,0));
    dp[0][0] = 1;
    ll ans = 0;
    rep(i,n) {
        rep(j,s+1) {
            if (j == 0) dp[i+1][j] = dp[i][j] + 1;
            else {
                if (j < s) dp[i+1][j] += dp[i][j];
                int prev = j - a[i];
                if (prev >= 0) dp[i+1][j] += dp[i][prev];
                dp[i+1][j] %= MOD;
            }
        }
        ans += dp[i+1][s] * (n - i) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}