#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

ll dp[200001][3];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    memset(dp, 0xc0, sizeof(dp));

    if (n % 2 == 0) {
        for (int i = 0; i < 2; i++) dp[i][i] = a[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                if (i - 2 >= 0) dp[i][j] = max(dp[i][j], dp[i - 2][j] + a[i]);
                if (i - 3 >= 0 && j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i - 3][j - 1] + a[i]);
            }
        }
        ll ans = max({dp[n - 2][0], dp[n - 1][1]});
        cout << ans << endl;
    } else {
        for (int i = 0; i < 3; i++) dp[i][i] = a[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                if (i - 2 >= 0) dp[i][j] = max(dp[i][j], dp[i - 2][j] + a[i]);
                if (i - 3 >= 0 && j - 1 >= 0) dp[i][j] = max(dp[i][j], dp[i - 3][j - 1] + a[i]);
                if (i - 4 >= 0 && j - 2 >= 0) dp[i][j] = max(dp[i][j], dp[i - 4][j - 2] + a[i]);
            }
        }
        ll ans = max({dp[n - 3][0], dp[n - 2][1], dp[n - 1][2]});
        cout << ans << endl;
    }
    return 0;
}
