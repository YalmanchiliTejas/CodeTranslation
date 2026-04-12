#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <string>
#include <vector>
#include <set>
using namespace std;

#define int long long
#define rep(n, i) for (int i = 0; i < n; i++)
#define rep2(m, n, i) for (int i = m; i < n; i++)
#define rep_r(n, i) for (int i = n - 1; i >= 0; i--)

const int INF = 1LL << 60;
const int MOD = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    int a[n];
    rep(n, i) {
        cin >> a[i];
        a[i] = -a[i];
    }
    int dp[n + 1];
    fill(dp, dp + n + 1, INF);
    dp[0] = a[0];
    rep2(1, n, i) {
        *upper_bound(dp, dp + n + 1, a[i]) = a[i];
    }
    rep(n + 1, i) {
        if (dp[i] == INF) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}