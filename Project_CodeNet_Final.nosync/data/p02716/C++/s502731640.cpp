// 6/18 振り返り
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

ll INF = 1e18;
ll dp[200005][4];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int k = 1 + n % 2;  // 何個余分な×を入れられるか？偶数なら１個、奇数なら２個。
    rep(i, n+1) rep(j, k+1) dp[i][j] = -INF;
    dp[0][0] = 0;
    rep(i, n) {
        rep(j, k+1) {
            // ×（余白）を一個挿入する場合
            // dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
            dp[i+1][j+1] = dp[i][j];

            // x（余白）を挿入しない場合
            ll now = dp[i][j];
            if ((i+j)%2 == 0) now += a[i];
            dp[i+1][j] = max(dp[i+1][j], now);
        }
    }
    ll ans = dp[n][k];
    cout << ans << endl;
}