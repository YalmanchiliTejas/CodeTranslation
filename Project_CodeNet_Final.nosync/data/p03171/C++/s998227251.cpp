#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll dp[n][n][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[i][i][0] = v[i];
        dp[i][i][1] = -v[i];
    }
    for (int w = 2; w <= n; w++) {
        for (int i = 0; i < n - w + 1; i++) {
            int j = i + w - 1;
            dp[i][j][0] = max(v[i] + dp[i+1][j][1], dp[i][j-1][1] + v[j]);
            dp[i][j][1] = min(-v[i] + dp[i+1][j][0], dp[i][j-1][0] - v[j]);
        }
    }
    cout << dp[0][n-1][0];
    return 0;
}
