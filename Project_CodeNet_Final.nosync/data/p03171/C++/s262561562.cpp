#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int n;
int a[3005];
const ll INF = 1e18;

// dp[i][j] 区間[i,j)におけるX-Yの値
ll dp[3005][3005];

ll solve(int i, int j) {
    if(dp[i][j] != -INF) return dp[i][j];
    if (j - i == 0) return dp[i][j] = 0;

    if ((n-(j-i)) % 2 == 0) {
        // 先手
        dp[i][j] = max(solve(i+1, j) + a[i], solve(i, j-1) + a[j-1]);      
    } else {
        // 後手
        dp[i][j] = min(solve(i+1, j) - a[i], solve(i, j-1) - a[j-1]);
    }

    return dp[i][j];
}

int main() 
{
    cin >> n;
    rep(i,n) cin >> a[i];
    rep(i,3005)rep(j,3005) dp[i][j] = -INF;

    ll ans = solve(0, n);
    cout << ans << endl;

    return 0;
}
