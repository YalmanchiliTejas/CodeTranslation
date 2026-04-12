#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    string s;
    cin >> s >> k;
    n = s.length();
    ll dp[101][101];
    memset(dp, 0, sizeof(dp));
    ll cnt = 0;
    for (ll i = 2; i <= n; ++i) {
        dp[i][0] = 1;
    }
    for (ll i = 1; i <= n; i++) {
        if (s[i - 1] > '0') {
            dp[i][cnt] += 1;
            dp[i][cnt + 1] += (s[i - 1] - '0' - 1);
            cnt++;
        }
        for (ll j = 1; j <= min(i, k); ++j) {
            dp[i][j] += dp[i - 1][j - 1] * 9 + dp[i - 1][j];
        }
    }
    cout << (cnt == k ? dp[n][k] + 1 : dp[n][k]);
    return 0;
}