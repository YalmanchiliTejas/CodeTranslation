#include <bits/stdc++.h>

using namespace std;

long long MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<long long>> dp(n+1, vector<long long>(s+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int v = a[i-1];
        for (int j = 0; j <= s; j++) {
            auto cur = (dp[i-1][j] + (j == 0 ? 1 : 0)) % MOD;
            if (j >= v) {
                cur = (cur + dp[i-1][j-v]) % MOD;
            }
            dp[i][j] = cur;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i][s]) % MOD;
    }
    cout << ans << endl;
}

