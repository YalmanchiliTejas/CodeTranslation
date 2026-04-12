#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    string S;
    cin >> S;
    int K = S.size();
    int D;
    cin >> D;
    ll mod = 1e9+7;
    
    vector<vector<vector<ll>>> dp(K+1, vector<vector<ll>>(D, vector<ll>(2, 0)));
    dp[0][0][1] = 1;
    
    for (int i = 1; i <= K; i++) {
        int d = (int)(S[i-1]-'0');
        for (int j = 0; j < D; j++) {
            dp[i-1][j][1] %= mod;
            dp[i-1][j][0] %= mod;
            dp[i][(j+d)%D][1] = dp[i-1][j][1];
            for (int k = 0; k <= 9; k++) {
                if (k < d) dp[i][(j+k)%D][0] += dp[i-1][j][1];
                dp[i][(j+k)%D][0] += dp[i-1][j][0];
            }
        }
    }
    
    ll ans = (dp[K][0][0] + dp[K][0][1] - 1) % mod;
    cout << ans << endl;
    return 0;
}