#include "bits/stdc++.h"
#pragma GCC optimize "03"
using namespace std;

#define int long long int
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define IOS ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef LOCAL
#define dbg(...) ;
#define endl '\n'
#endif

const int inf = 1e15;
const int MOD = 998244353;
const int N = 3006;

int a[N], dp[N][N];

signed main(){
    IOS;
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        dp[i][a[i]] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            if (j >= a[i]) dp[i][j] += dp[i-1][j] + dp[i-1][j-a[i]];
            else dp[i][j] += dp[i-1][j];
            dp[i][j] %= MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i][s];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}