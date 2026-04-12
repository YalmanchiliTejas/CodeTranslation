#include <bits/stdc++.h>
using namespace std;
#define mod 998244353

long long dp[3010][3010];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, s; cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            long long add = 0;
            if (j >= a[i]) add = dp[i][j-a[i]];
            if (j == s) add *=  n-i;
            if (j == a[i]) add *= i+1;
            dp[i+1][j] = (dp[i+1][j] + dp[i][j] + add) % mod;
        }
    }
    cout << dp[n][s] << "\n";
    return 0;
}