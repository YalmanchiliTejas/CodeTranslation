#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = int64_t;

int main(){
    int n; cin >> n;
    int a[n]; rep(i, n) cin >> a[i];

    int k = 1+n%2;
    ll dp[n+1][4];
    rep(i, n+1)rep(j, k+1) dp[i][j] = INT64_MIN/2;
    dp[0][0] = 0;
    rep(i, n){
        rep(j, k+1){
            dp[i+1][j+1] = max<ll>(dp[i+1][j+1], dp[i][j]);
            ll now = dp[i][j];
            if((i+j)%2 == 0) now += a[i];
            dp[i+1][j] = max<ll>(dp[i+1][j], now);
        }
    }
    cout << dp[n][k] << endl;

    return 0;
}