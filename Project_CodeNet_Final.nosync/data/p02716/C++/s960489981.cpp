#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    ll a[n];
    rep(i, n) {
        cin >> a[i];
    }
    if(n % 2 == 0){
        ll dp[n][2];
        fill(dp[0], dp[n], -LINF);
        dp[0][0] = a[0];
        dp[1][1] = a[1];
        for (int i = 0; i < n; i++) {
            rep(j, 2) {
                if (i - 2 >= 0) dp[i][j] = max(dp[i][j], dp[i - 2][j] + a[i]);
            }
            if (i - 3 >= 0) dp[i][1] = max(dp[i][1], dp[i - 3][0] + a[i]);
        }
        cout << max(dp[n - 1][1], dp[n - 2][0]) << endl;
    }else{
        ll dp[n][3];
        fill(dp[0], dp[n], -LINF);
        dp[0][0] = a[0];
        dp[1][1] = a[1];
        dp[2][2] = a[2];
        for (int i = 0; i < n; i++) {
            rep(j, 3) {
                if (i - 2 >= 0) dp[i][j] = max(dp[i][j], dp[i - 2][j] + a[i]);
            }
            if (i - 3 >= 0) dp[i][1] = max(dp[i][1], dp[i - 3][0] + a[i]);
            if (i - 3 >= 0) dp[i][2] = max(dp[i][2], dp[i - 3][1] + a[i]);
            if (i - 4 >= 0) dp[i][2] = max(dp[i][2], dp[i - 4][0] + a[i]);
        }
        cout << max({dp[n - 1][2], dp[n - 2][1], dp[n - 3][0]}) << endl;
    }
    return 0;
}