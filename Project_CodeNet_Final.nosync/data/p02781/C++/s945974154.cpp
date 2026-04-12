#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string n;
    cin >> n;
    int k;
    cin >> k;
    int m = n.size();
    vector<vector<vector<ll>>> dp(m + 1, vector<vector<ll>>(5, vector<ll>(2)));
    dp[0][0][1] = 1;
    rep(i, 0, m) {
        rep(j, 0, 4) {
            dp[i + 1][j][0] += dp[i][j][0];
            dp[i + 1][j + 1][0] += dp[i][j][0] * 9ll;
        }
        int t = n[i] - '0';
        if (t) {
            rep(j, 0, 4) {
                dp[i + 1][j + 1][1] += dp[i][j][1];
                dp[i + 1][j][0] += dp[i][j][1];
                dp[i + 1][j + 1][0] += dp[i][j][1] * (t - 1);
            }
        } else {
            rep(j, 0, 4) {
                dp[i + 1][j][1] += dp[i][j][1];
            }
        }
    }
    cout << dp[m][k][0] + dp[m][k][1] << endl;
    return 0;
}