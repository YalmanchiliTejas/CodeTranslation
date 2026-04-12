#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

using lint = long long;
constexpr lint INF = 1LL << 60;

void solve() {
    int n;
    std::cin >> n;

    if (n % 2 == 0) {
        auto dp = vec(2, vec(n + 2, -INF));
        dp[0][0] = 0;
        for (int i = 0; i <= n; ++i) {
            lint x;
            if (i >= n) {
                x = 0;
            } else {
                std::cin >> x;
            }

            dp[1][i + 1] = std::max(dp[1][i + 1], dp[0][i]);
            if (i == n) break;

            for (int k = 0; k < 2; ++k) {
                dp[k][i + 2] = std::max(dp[k][i + 2], dp[k][i] + x);
            }
        }

        std::cout << dp[1][n + 1] << std::endl;

    } else {
        auto dp = vec(3, vec(n + 2, -INF));
        dp[0][0] = 0;
        for (int i = 0; i <= n; ++i) {
            lint x;
            if (i >= n) {
                x = 0;
            } else {
                std::cin >> x;
            }

            for (int k = 0; k < 2; ++k) {
                dp[k + 1][i + 1] = std::max(dp[k + 1][i + 1], dp[k][i]);
            }
            if (i == n) break;

            for (int k = 0; k < 3; ++k) {
                dp[k][i + 2] = std::max(dp[k][i + 2], dp[k][i] + x);
            }
        }

        std::cout << dp[2][n + 1] << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}
