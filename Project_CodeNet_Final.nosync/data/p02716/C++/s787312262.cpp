#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define rep11(i,n) for(int i=1;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define repm(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb(n) push_back(n)
#define mp make_pair
#define INF LONG_LONG_MAX
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int n,a[200001],dp[3][200100];

signed main() {
    rep(i,3) rep(j,200004) dp[i][j] = -INF/10;
    cin >> n;
    rep1(i,n) cin >> a[i];
    dp[0][0] = dp[1][0] = dp[2][0] = dp[1][1] = dp[2][1] = dp[2][2] = 0;
    dp[0][1] = a[1];
    dp[0][2] = a[2];

    repo(i,3,n+1) {
        dp[0][i] = max(dp[0][i], dp[0][i-2] + a[i]);
        dp[1][i] = max(dp[1][i], dp[1][i-2] + a[i]);
        dp[2][i] = max(dp[2][i], dp[2][i-2] + a[i]);
        dp[1][i] = max(dp[1][i], dp[0][i-3] + a[i]);
        dp[2][i] = max(dp[2][i], dp[1][i-3] + a[i]);
        if (i >= 4) dp[2][i] = max(dp[2][i], dp[0][i-4] + a[i]);

    }
    int ans = -INF;
    if (n%2 == 1) {
        ans = max(ans, dp[0][n-2]);
        ans = max(ans, dp[0][n-1]);
        ans = max(ans, dp[0][n]);
        ans = max(ans, dp[1][n-1]);
        ans = max(ans, dp[1][n]);
        ans = max(ans, dp[2][n]);
    }
    else {
        ans = max(ans, dp[0][n-1]);
        ans = max(ans, dp[0][n]);
        ans = max(ans, dp[1][n]);
    }
    cout << ans << endl;
}



