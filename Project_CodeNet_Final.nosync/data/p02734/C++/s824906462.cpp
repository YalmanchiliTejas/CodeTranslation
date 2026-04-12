#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
        #include "debug.h"
        #define input freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        #else
        #define debug(...) 4
        #define input ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif

using ll = long long;
const int N = 2e5 + 5;
const int mod = 998244353;
ll dp[3005][3005];
inline int power(int x, int y, int res = 1) {
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    } return res;
}

int main() {
    input;
    int n, s;
    cin >> n >> s;
    int a[n];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // dp[i][j] = sum of left endpoints of subsequences with sum j that end at i 
    for(int i = 1; i <= n; i++) {
        dp[i][a[i]] = i;

        for(int j = 0; j <= s; j++) {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
            if(j - a[i] >= 0) {            
                dp[i][j] += dp[i - 1][j - a[i]];
                dp[i][j] %= mod;
            }
        }
        
    }
    for(int i = 1; i <= n; i++) {
        debug(dp[i][s]);
        dp[i][s] += dp[i - 1][s];
        dp[i][s] %= mod;
    }


    cout << dp[n][s];
}
