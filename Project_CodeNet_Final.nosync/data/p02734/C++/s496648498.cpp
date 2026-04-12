typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n,s;
    std::cin >> n>> s;
    
    vector<ll> a(n);
    const ll MOD = 998244353;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    vector<vector<ll>> dp(n+1,vector<ll>(3001,0));
    dp[0][0] = 1;
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j= 0; j <= s; j++) {
            dp[i+1][j] = dp[i][j];
        }
        for (int j = a[i]; j <= s; j++) {
            dp[i+1][j] += dp[i][j-a[i]];
            dp[i+1][j] %= MOD;
        }
        dp[i+1][a[i]]+=i;
    }
    for (int i = 1; i <= n; i++) {
        ans += dp[i][s];
        ans %= MOD;
    }
    std::cout << ans << std::endl;
}

