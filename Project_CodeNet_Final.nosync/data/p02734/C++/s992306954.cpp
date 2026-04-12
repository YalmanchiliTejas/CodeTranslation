#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MN = 3e3 + 5, MOD = 998244353;
int N, S, a[MN]; ll dp[MN][MN]; 

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> S;
    ll ans = 0;
    for (int i = 1; i <= N; i++) cin >> a[i];
    // dp[i][j] = fixed right bracket at i, way to sum to j
    for (int i = 1; i <= N; i++) {
        // dont use current value
        for (int j = 0; j <= S; j++) dp[i][j] = dp[i - 1][j];
        // only use current value, i places to place left bracket
        (dp[i][a[i]] += i) %= MOD;
        // use current value with previous states, 
        for (int j = a[i]; j <= S; j++) (dp[i][j] += dp[i - 1][j - a[i]]) %= MOD;
        ans = (ans + dp[i][S]) % MOD;
    }
    cout << ans << '\n';
    return 0;
}