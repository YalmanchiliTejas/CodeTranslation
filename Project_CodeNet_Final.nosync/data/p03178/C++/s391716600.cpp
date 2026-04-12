#include <iostream>
#include <vector>
constexpr int MOD = 1e9 + 7;
template <typename T>
std::vector<T> Vec(const std::size_t n, T v) { return std::vector<T>(n, v); }
template <class... Args>
auto Vec(const std::size_t n, Args... args) { return std::vector<decltype(Vec(args...))>(n, Vec(args...)); }
int main()
{
    std::string K;
    std::cin >> K;
    const int N = K.size();
    int D;
    std::cin >> D;
    auto dp = Vec(N + 1, D, 2, 0);
    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        const int dig = K[i] - '0';
        for (int j = 0; j < D; j++) {
            for (int k = 0; k < 2; k++) {
                for (int d = 0; d <= (k ? 9 : dig); d++) {
                    const int nj = (j + d) % D;
                    const bool nk = k or d < dig;
                    (dp[i + 1][nj][nk] += dp[i][j][k]) %= MOD;
                }
            }
        }
    }
    std::cout << (dp[N][0][0] + dp[N][0][1] + MOD - 1) % MOD << std::endl;
    return 0;
}
