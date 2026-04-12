#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;

signed main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto& x : a)
        cin >> x;
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for(ll i = 0; i < n; ++i)
        for(ll j = i; j < n; ++j)
            dp[i][j] = ((n - (j - i)) % 2 == 1 ? -1e18 : 1e18);

    for(ll i = 0; i < n; ++i)
        dp[i][i] = (dp[i][i] < 0 ? 1 : -1) * a[i];

    for(ll k = 1; k < n; ++k){
        for(ll i = 0, j = k; j < n; ++i, ++j){
            bool sente = (n - (j - i)) % 2;
            if(sente){
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j]);
            }else{
                dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
}
