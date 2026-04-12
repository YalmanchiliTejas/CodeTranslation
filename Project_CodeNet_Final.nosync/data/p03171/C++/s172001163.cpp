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
#define int long long
int dp[3010][3010];
int a[3010];
int N;
int dfs(int L, int R, bool turn) {
    //cout << L << " " << R << " " << turn << endl;
    if (dp[L][R] != INF2) return dp[L][R];
    if (L + R == N - 1) {
        if (N % 2 == 0)
            return dp[L][R] = -a[L];
        else
            return dp[L][R] = a[L];
    }
    if(turn) {
        int tmpL = dfs(L + 1, R, !turn) + a[L];
        int tmpR = dfs(L, R + 1, !turn) + a[N - R - 1];
        return dp[L][R] = max(tmpL, tmpR);
    } else {
        int tmpL = dfs(L + 1, R, !turn) - a[L];
        int tmpR = dfs(L, R + 1, !turn) - a[N - R - 1];
        return dp[L][R] = min(tmpL, tmpR);   
    }
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N) cin >> a[i];
    rep(i, 3010) rep(j, 3010) dp[i][j] = INF2;
    cout << dfs(0, 0, true) << endl;
    //rep(i, N) rep(j, N) cout << i << " " << j << " " << dp[i][j] << endl;
    

    return 0;
}
