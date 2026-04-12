#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <functional>
#include <set>
#include <cmath>

using namespace std;
#define get(x) if (DEBUG) cout << #x << " : " << x << endl;
#define print(x) if (DEBUG) cout << x << endl;
#define int long long
#define double long double

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

const int MAX = (int)1e6;
const long long INF = 1e18;

signed main() {
    fast();
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int dp[n][n][2];
    for (int i = 0; i < n; ++i) {
        dp[i][i][0] = a[i];
        dp[i][i][1] = 0;
    }
    for (int len = 1; len < n; ++len) {
        for (int i = 0; i < n - len; ++i) {
            dp[i][i + len][0] = max(dp[i][i + len - 1][1] + a[i + len],
                                    dp[i + 1][i + len][1] + a[i]);
            dp[i][i + len][1] = min(dp[i][i + len - 1][0], dp[i + 1][i + len][0]);
        }
    }
    cout << 2 * dp[0][n - 1][0] - sum;

    return 0;
}