#include <bits/stdc++.h>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;

constexpr auto M = 1000000007;

main() {
    int64_t n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    vector<vector<int64_t>> combi(n + 1);
    combi[0].resize(1, 1);
    for (auto i : irange(1L, n + 1)) {
        combi[i].resize(i + 1);
        combi[i][0] = 1;
        combi[i][i] = 1;
        for (auto j : irange(1L, i)) {
            combi[i][j] = combi[i - 1][j - 1] + combi[i - 1][j];
            combi[i][j] %= M;
        }
    }

    // K人を全てのグループがi人以下であるようにグループ分けする数 = dp[i][K]
    vector<vector<int64_t>> dp(b + 1, vector<int64_t>(n + 1));
    dp[0][0] = 1;
    for (auto i : irange(0L, a)) {
        dp[i][0] = 1;
    }
    // k人からg個のi人のグループを作る数 = dp2[k][g]
    vector<vector<int64_t>> dp2(n + 1, vector<int64_t>(n));
    for (auto i : irange(a, b + 1)) {
        dp[i][0] = 1;
        dp2[0][0] = 1;
        for (auto k : irange(1L, n + 1)) {
            dp2[k][0] = 1;
            dp[i][k] = dp[i - 1][k];
            // i人ちょうどのグループがg個あるとする
            for (auto g = 1L; g < c; ++g) {
                if (k < i) {
                    dp2[k][g] = 0;
                } else {
                    dp2[k][g] = (((i * g <= k - 1) ? dp2[k - 1][g] : 0) +
                             (dp2[k - i][g - 1] * combi[k - 1][i - 1]) % M) %
                            M;
                }
            }
            for (auto g = c; i * g <= k && g <= d; ++g) {
                dp2[k][g] = (((i * g <= k - 1) ? dp2[k - 1][g] : 0) +
                             (dp2[k - i][g - 1] * combi[k - 1][i - 1]) % M) %
                            M;
                dp[i][k] += (dp2[k][g] * dp[i - 1][k - g * i]) % M;
                dp[i][k] %= M;
            }
        }
    }

    for (auto i : irange(0L, b + 1)) {
        for (auto j : irange(0L, n + 1)) {
            // cerr << i << "," << j << ":" << dp[i][j] << "\n";
        }
    }

    cout << dp[b][n] << endl;
}
