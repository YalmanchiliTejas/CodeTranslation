#include "bits/stdc++.h"
#define int long long
using namespace std;

const int mod = 1e9 + 7;

int32_t main() {
    string s;
    cin >> s;
    int d;
    cin >> d;
    vector<vector<int>> dp(s.size() + 1, vector<int>(d, 0));
    dp[0][0] = 1;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < 10; k++) {
                dp[i + 1][(j + k) % d] += dp[i][j];
                dp[i + 1][(j + k) % d] %= mod;
            }
        }
    }
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s[i] - '0'; j++) {
            ans += dp[s.size() - i - 1][(d - (cur + j) % d) % d];
            ans %= mod;
        }
        cur += s[i] - '0';
        cur %= d;
    }
    if (cur == 0) {
        ans++;
        ans %= mod;
    }
    ans += mod - 1;
    ans %= mod;
    cout << ans << endl;
}
