#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using namespace std;

#define INF ((1<<30)-1)
#define LLINF (1LL<<60)
#define EPS (1e-10)

// dp[i][j] := 元の数列から連続する区間a_i, a_i+1,...,a_j-1を抜き出した状態の局面から出発して，双方最善を尽くしたときのX-Yの値
// [i, j)

// 左側を取る [i+1, j)
// 右側を取る [i, j-1)
// 区間幅 len = j - iが0の場合が終わり
// 区間幅 len = j - 1の場合が次に決まる...
ll dp[3030][3030];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            int j = i + len;
            if ((n - len) % 2 == 0) {
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
            }
            else {
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
            }
        }
    }

    cout << dp[0][n] << endl;
}
