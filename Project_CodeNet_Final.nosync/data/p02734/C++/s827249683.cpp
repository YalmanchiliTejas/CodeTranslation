#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MN = 3000 + 5, LN = 17, MOD = 998244353, INF = 0x3f3f3f3f, BSZ = 320;
int N, S;
int a[MN];
ll dp[MN][MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> S;
    for (int i = 1; i <= N; i++) cin >> a[i];
    ll ret = 0;
    // dp[i][j], how many ways to place open brackets at [1,i] and sum of j
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= S; j++) dp[i][j] = dp[i - 1][j];
        (dp[i][a[i]] += i) %= MOD;
        for (int j = S; j >= a[i]; j--) {
            (dp[i][j] += dp[i - 1][j - a[i]]) %= MOD;
        }
        ret = (ret + dp[i][S]) % MOD;
    }
    cout << ret << '\n';
    return 0;
}
