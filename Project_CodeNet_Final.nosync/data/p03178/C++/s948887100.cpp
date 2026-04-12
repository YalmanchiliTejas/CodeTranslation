#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int dp[10010][2][110];

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string K; cin >> K;
    int n = K.length();
    int D; cin >> D;
    dp[0][0][0] = 1;
    rep(i, n) {
        rep(j, D) {
            rep(dig, 10) dp[i + 1][1][(j + dig) % D] = (dp[i + 1][1][(j + dig) % D] + dp[i][1][j]) % mod;
            rep(dig, K[i] - '0')  dp[i + 1][1][(j + dig) % D] = (dp[i + 1][1][(j + dig) % D] + dp[i][0][j]) % mod;
            dp[i + 1][0][(j + K[i] - '0') % D] = (dp[i + 1][0][(j + K[i] - '0') % D] + dp[i][0][j]) % mod;
        }
    }
    cout << (dp[n][0][0] + dp[n][1][0] - 1 + mod) % mod << endl;

    return 0;
}
