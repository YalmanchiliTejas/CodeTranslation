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
    dp[0][0 - 1/2+25] = 0;
    dp[0][1 - 1/2+25] = a[0];
    dp[1][0 - 2/2+25] = 0;
    dp[1][1 - 2/2+25] = a[1];
    for(ll i=1; i<n; i++) {
        for(ll j=max(0ll,(i+1)/2-2); j<=min(n-1, (i+1)/2+2); j++) {
            dp[i][j - (i+1)/2 + 25] = max(dp[i][j - (i+1)/2 + 25], dp[i-1][j - i/2 + 25]);
            if(i-2>=0 && j-1>=0) dp[i][j - (i+1)/2 + 25] = max(dp[i][j - (i+1)/2 + 25], dp[i-2][j-1 - (i-1)/2 + 25] + a[i]);
        }
    }
    cout << dp[n-1][n/2 - n/2 + 25] << endl;

}
