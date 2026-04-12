#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using namespace std;

#define INF ((1<<30)-1)
#define LLINF (1LL<<60)
#define EPS (1e-10)

// dp[l][r] := l以上r未満の範囲をもらったときのX-Yの最大値

// dp[i][i] = 0
// 太郎の場合
// dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r-1])
// dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r-1])

// 区間DP
ll dp[3300][3300];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    for (int width = 1; width <= n; ++width) {
        for (int l = 0; l+width <= n; ++l) {
            int r = l+width;

            // 先手
            if (width % 2 == n%2) {
                dp[l][r] = max(dp[l+1][r] + a[l], dp[l][r-1] + a[r-1]);
            }
            else {
                dp[l][r] = min(dp[l+1][r] - a[l], dp[l][r-1] - a[r-1]);
            }
        }
    }

    cout << dp[0][n] << endl;
}
