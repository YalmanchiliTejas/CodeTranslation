#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3009;
int n, a[N], dp[N][N][2];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int len = 1; len <= n; ++len) {
        for(int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            if(i == j) {
                dp[i][i][0] = a[i];
                dp[i][i][1] = -a[i];
                continue;
            }
            dp[i][j][0] = max(a[i] + dp[i + 1][j][1], a[j] + dp[i][j - 1][1]);
            dp[i][j][1] = min(-a[i] + dp[i + 1][j][0], -a[j] + dp[i][j - 1][0]);
        }
    }
    cout << dp[1][n][0] << endl;
}