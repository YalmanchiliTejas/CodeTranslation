 #pragma GCC optimize("O3")
 #pragma GCC optimize("unroll-loops")
 #pragma GCC optimize("fast-math")
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define int long long
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void accell() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}
const int N = 2000;
int dp[N][N];
char c[N][N];
signed main() {
    accell();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c[i][j];
        }
    }
    dp[0][0] = c[0][0] == '#';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i && c[i][j] == '#' && c[i - 1][j] == '#') dp[i][j] = max(dp[i][j], (int)(dp[i - 1][j] + 1));
            if (j && c[i][j] == '#' && c[i][j - 1] == '#') dp[i][j] = max(dp[i][j], (int)(dp[i][j - 1] + 1));
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans = max(ans, dp[i][j]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans -= c[i][j] == '#';
    if (ans == 0)
        cout << "Possible";
    else
        cout << "Impossible";
    return 0;
}
