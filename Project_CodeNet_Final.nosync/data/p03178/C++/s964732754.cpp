#include <bits/stdc++.h>

#define int long long

using namespace std;

const int mod = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int d;
    cin >> d;
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(d, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < 10; ++k) {
                dp[i + 1][(j + k) % d] += dp[i][j];
                dp[i + 1][(j + k) % d] %= mod;
            }
        }
    }
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i] - '0'; j++) {
            ans += dp[n - i - 1][(2 * d - sum - j % d) % d];
            ans %= mod;
        }
        sum += s[i] - '0';
        sum %= d;
    }
    if (sum == 0) {
        ans++;
        ans %= mod;
    }
    ans += mod - 1;
    ans %= mod;
    cout << ans << endl;
}
