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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3010;

int dp[maxn][maxn];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &el : a) cin >> el;
    for (int len = 0; len < n; len++) {
        for (int l = 0; l + len < n; l++) {
            int r = l + len;
            if (len == 0) {
                if ((n - len - 1) % 2 == 0) {
                    dp[l][l] = a[l];
                } else {
                    dp[l][l] = -a[l];
                }
            } else {
                if ((n - len - 1) % 2 == 0) {
                    dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r]);
                } else {
                    dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r]);
                }
            }
        }
    }
    cout << dp[0][n - 1] << "\n";


    return 0;
}