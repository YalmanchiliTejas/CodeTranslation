#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;

ll constexpr N = 200009;
ll f[N];
ll constexpr MOD = 1000000007;

ll mp(ll a, ll b) {
    if(b == 0)
        return 1;
    ll h = mp(a, b / 2);
    if(b & 1)
        return (((h * h) % MOD) * a) % MOD;
    return (h * h) % MOD;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> dp(n + 10, vector<ll>(m + 10)),
                       dp2(n + 10, vector<ll>(m + 10));
    
    ll sum = 0;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) {
            dp2[i][j] = j * (j - 1) / 2 + dp2[i - 1][j] + (i - 1) * j;

            dp[i][j] += dp2[i - 1][j] + (i - 1) * j;
            dp[i][j] %= MOD;
            dp[i][j] += dp2[i - 1][m - j] + 2 * (i - 1) * (m - j);
            dp[i][j] %= MOD;            
            dp[i][j] += j * (j - 1) / 2;
            dp[i][j] %= MOD;
            sum += dp[i][j];
            sum %= MOD;
        }
    }
    f[0] = 1;
    for(ll i = 1; i < N; ++i) {
        f[i] = (f[i - 1] * i) % MOD;
    }

    ll x = m * n - 2;
    ll y = k - 2;
    ll ans = sum * f[x];
    ans %= MOD;
    ans *= mp(f[y], MOD - 2);

    ans %= MOD;
    ans *= mp(f[x - y], MOD - 2);
    ans %= MOD;


    cout << ans << endl;
}