#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


ll dp[3100][6600][3];

int main() {
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    rep(i, 0, n) rep(j, 0, s+1) {
        // from 0
        (dp[i+1][j][0] += dp[i][j][0] ) %= MOD;
        (dp[i+1][j+a[i]][1] += dp[i][j][0] * (i+1)) %= MOD;
        (dp[i+1][j+a[i]][2] += dp[i][j][0] * (i+1) * (n-i)) %= MOD;

        // from 1
        (dp[i+1][j][1] += dp[i][j][1]) %= MOD;
        (dp[i+1][j+a[i]][1] += dp[i][j][1]) %= MOD;
        (dp[i+1][j+a[i]][2] += dp[i][j][1] * (n-i)) %= MOD;

        // from 2
        (dp[i+1][j][2] += dp[i][j][2]) %= MOD;
    }

    cout << dp[n][s][2] % MOD << endl;
}
