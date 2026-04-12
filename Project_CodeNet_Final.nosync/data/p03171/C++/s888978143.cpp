#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int64_t dp[3300][3300];

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];
    rep(i,n) dp[i][i] = 0;
    for (int width = 1; width <= n; width++) {
        for (int lef = 0; lef + width <= n; lef++) {
            int rig = lef + width;
            if (width % 2 == n % 2) {
                dp[lef][rig] = max(dp[lef+1][rig] + a[lef], dp[lef][rig-1] + a[rig-1]);
            }
            else {
                dp[lef][rig] = min(dp[lef+1][rig] - a[lef], dp[lef][rig-1] - a[rig-1]);
            }
        }
    }
    cout << dp[0][n] << endl;
}