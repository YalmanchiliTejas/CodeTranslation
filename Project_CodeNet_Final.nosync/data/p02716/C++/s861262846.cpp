#include <bits/stdc++.h>
using namespace std;
using large = long long;
constexpr large fail = LLONG_MIN / 2;
// divide by 2 to make space for adding negative values

//       pos   skip  used
large dp[200'010][3][2];

template <class T, size_t N, class V> void fill_(T (&a)[N], V v) {
    for (auto &elem : a)
        elem = v;
}

template <class T, size_t N, size_t M, class V> void fill_(T (&md)[N][M], V val) {
    for (auto &row : md)
        fill_(row, val);
}

int main() {
    int n;
    cin >> n;
    auto a = vector<int>(n);
    for (auto &a_i : a)
        cin >> a_i;

    int cnt = n / 2;
    int max_skips = n - (2 * cnt - 1);
    // cerr << "n:" << n << " max_skips:" << max_skips << "\n";

    fill_(dp, fail);
    dp[0][0][0] = 0;
    dp[0][1][0] = 0;
    dp[0][2][0] = 0;

    for (int i = 0; i < n; ++i) {
        // use i'th
        dp[i + 1][0][1] = dp[i][0][0] + a[i];
        dp[i + 1][1][1] = dp[i][1][0] + a[i];
        dp[i + 1][2][1] = dp[i][2][0] + a[i];

        // don't use i'th
        dp[i + 1][0][0] = dp[i][0][1];
        dp[i + 1][1][0] = max(dp[i][1][1], dp[i][0][0]);
        dp[i + 1][2][0] = max(dp[i][2][1], dp[i][1][0]);
    }

    auto ans = max(dp[n][max_skips][0], dp[n][max_skips][1]);
#if 0
    for (int sk = 0; sk < max_skips; ++sk) {
        auto pos = n - (max_skips - sk);
        ans = max({ans, dp[pos][sk][0], dp[pos][sk][1]});
    }
#endif
    cout << ans << "\n";
    return 0;
}
