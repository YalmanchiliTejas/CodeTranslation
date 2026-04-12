#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &e: a) cin >> e;
    vector<vector<ll>> dp(n, vector<ll>(50, -1e18));
    dp[0][1 + 25] = a[0];
    dp[0][-1 + 25] = 0;
    dp[1][0 + 25] = a[1];
    dp[1][-2 + 25] = 0;
    for(ll i=1; i<n; i++) {
        for(ll j=-3; j<=3; j++) {
            if(i-2>=0) dp[i][j + 25] = max(dp[i][j+1 + 25], dp[i-2][j + 25] + a[i]);
            dp[i][j-1 + 25] = max(dp[i][j-1 + 25], dp[i-1][j + 25]);
        }
    }
    cout << dp[n-1][n/2 - (n+1)/2 + 25] << endl;

}
