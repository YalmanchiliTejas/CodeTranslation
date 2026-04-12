#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int a[n+1]; FOR(i,1,n+1) cin >> a[i];

    ll dp[n+2][n+2][2];
    memset(dp, 0, sizeof dp);
    RFOR(i,n,1) FOR(j,1,n) FOR(t,0,1) {
        if (i>j) continue;

        if (t == 0) {
            dp[i][j][t] = max(a[i]+dp[i+1][j][!t], a[j]+dp[i][j-1][!t]);
        } else {
            dp[i][j][t] = min(dp[i+1][j][!t]-a[i], dp[i][j-1][!t]-a[j]);
        }
        //cout << i << ' ' << j << ' ' << t << " :: " << dp[i][j][t] <<  endl;
    }
    cout << dp[1][n][0] << '\n';
}

