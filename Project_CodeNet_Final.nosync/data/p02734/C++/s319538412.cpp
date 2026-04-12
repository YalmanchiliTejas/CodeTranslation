#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 998244353
#define INF2 1000000000000000000
#define int long long

int dp[3010][6010];

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, S;
    cin >> N >> S;
    int A[3010];
    rep(i, N) cin >> A[i];
    dp[0][0] = 1;
    REP(i, 0, N) dp[i][0] = 1;
    rep(i, N) {
        RREP(j, S, 0) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j + A[i]] += dp[i][j];
            dp[i + 1][j] %= mod;
            dp[i + 1][j + A[i]] %= mod;
        }
    }
    int ans = 0;
    rep(i, N + 1) ans = (ans + dp[i][S]) % mod;
    cout << ans << endl;

    return 0;
}
// (1, 1) (1, 2) (1, 3)
// ()


//