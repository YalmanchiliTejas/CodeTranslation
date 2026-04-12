#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define int long long

const int N = 2e5 + 1;
int dp[N][2];
signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    dp[0][0] = 0;
    dp[0][1] = v[0];
    dp[1][0] = max(v[0], v[1]);
    dp[1][1] = max(v[0], v[1]);
    for (int i = 2; i < n; ++i) {
        if ((i + 1) % 2) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + v[i]);
            dp[i][1] = dp[i - 2][1] + v[i];
        } else {
            dp[i][0] = max(dp[i - 2][0] + v[i], dp[i - 1][1]);
            dp[i][1] = dp[i][0];
        }
    }

    cout << dp[n - 1][0];
}
