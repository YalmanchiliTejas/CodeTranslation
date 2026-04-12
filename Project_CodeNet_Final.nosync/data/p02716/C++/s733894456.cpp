#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
#define chmax(x,y) x = max(x,y)

// dp[i][j] : i番目まで見た時、余分な × をj個挿入しているときの数の和 
ll dp[2*100005][3];

const ll INF = ll(1e18)+1;

int main() 
{
    int n;
    cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];

    int k = n%2 + 1; // 挿入する × の数

    rep(i,n+1)rep(j,k+1) dp[i][j] = -INF;
    dp[0][0] = 0;
    rep(i,n) {
        rep(j,k+1) {
            // i番目に × を挿入する場合
            if (j+1 <= k) chmax(dp[i+1][j+1], dp[i][j]);

            // i番目に挿入しない場合
            if ((i+j)%2 == 0) chmax(dp[i+1][j], dp[i][j] + a[i]);
            else chmax(dp[i+1][j], dp[i][j]);
        }
    }

    ll ans = dp[n][k];
    cout << ans << endl;
    
    return 0;
}
