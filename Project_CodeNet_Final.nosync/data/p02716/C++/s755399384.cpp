#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
//#define double long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const int INF = 2e17;
const int MB = 20;
const int MOD = 1e9 + 7;
const int maxN = 1e3;

vector<int> suff;
vector<int> a;

void solve() {
    int n;
    cin >> n;
    
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m = n % 2 + 1;

    vector<vector<int>> dp(m + 1, vector<int>(n, -INF));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= m; j++) {
            dp[j][i] = max(dp[j][i], (i + 2 < n ? dp[j][i + 2] : 0) + a[i]);
            if (j && i + 3 < n) dp[j][i] = max(dp[j][i], dp[j - 1][i + 3] + a[i]);
        }
    }

    int ans = -INF;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m - i; j++) {
            ans = max(ans, dp[j][i]);
        }
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int t;
    //cin >> t;
    int t = 1;
    //srand(time(0));
    while (t--) solve();
}