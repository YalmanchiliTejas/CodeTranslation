#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

ll dp[3100][3100]; // dp[i][j] => [i, j) 半開区間

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    // 初期条件
    rep(i, N) dp[i][i] = 0;

    for (int len = 1; len <= N; ++len) {
        for (int i = 0; i + len <= N; ++i) {
            int j = i + len;

            // 先手番
            if ((N - len) % 2 == 0)
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);

                // 後手番
            else
                dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
        }
    }

    cout << dp[0][N] << endl;
}