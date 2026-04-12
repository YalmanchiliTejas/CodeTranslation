#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

using lint = long long;
constexpr lint INF = 1LL << 60;

void solve() {
    int n;
    std::cin >> n;

    int m = (n % 2 == 0 ? 1 : 2);

    auto dp = vec(m + 1, vec(n + 2, -INF));
    dp[0][0] = 0;

    for (int i = 0; i <= n; ++i) {
        lint x;
        if (i >= n) {
            x = 0;
        } else {
            std::cin >> x;
        }

        for (int k = 0; k + 1 <= m; ++k) {
            dp[k + 1][i + 1] = std::max(dp[k + 1][i + 1], dp[k][i]);
        }
        if (i == n) break;

        for (int k = 0; k <= m; ++k) {
            dp[k][i + 2] = std::max(dp[k][i + 2], dp[k][i] + x);
        }
    }

    std::cout << dp[m][n + 1] << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}
