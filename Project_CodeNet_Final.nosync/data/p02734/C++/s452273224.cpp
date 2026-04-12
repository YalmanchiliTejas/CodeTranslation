#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int n, s, ans;
ll a[3030], dp[3030][3030];
const ll MOD = 998244353;


int main(){
    cin >> n >> s;
    rep(i,n) cin >> a[i];

    rep(i,n) {
        rep(j,s+1) {
            dp[i+1][j] += dp[i][j];
            int prev = j - a[i];
            if (prev > 0) dp[i+1][j] += dp[i][prev];
            else if (prev == 0) dp[i+1][j] += i+1;
            dp[i+1][j] %= MOD;
        }
        ans = (ans + dp[i+1][s] * (n - i) % MOD) % MOD;
        dp[i+1][s] = 0;
    }

    cout << ans << endl;
    return 0;
}