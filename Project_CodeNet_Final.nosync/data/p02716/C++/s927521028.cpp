#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2")

using namespace std;

#define int long long
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define x first
#define y second

const int inf = 5e18;
const int maxn = 2e5 + 10;

int dp[maxn][3];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &el : a) {
        cin >> el;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = -inf;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            dp[i][0] = a[i];
        } else {
            for (int j = 0; j <= 2; j++) {
                for (int k = 0; k <= 2; k++) {
                    if (j + k > 2) continue;
                    if (i - k <= 0) {
                        dp[i][j + k] = max(dp[i][j + k], a[i]);
                    } else {
                        if (i - k - 2 < 0 || dp[i - k - 2][j] == -inf) continue;
                        dp[i][j + k] = max(dp[i][j + k], dp[i - k - 2][j] + a[i]);
                    }
                }
            }
        }
    }
    int ans;
    if (n % 2 == 0) {
        ans = max(dp[n - 1][1], dp[n - 2][0]);
    } else {
        ans = max(dp[n - 1][2], dp[n - 2][1]);
    }
    cout << ans << "\n";

    return 0;
}