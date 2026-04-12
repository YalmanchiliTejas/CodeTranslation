#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

constexpr intmax_t mod = 1e9+7;

std::vector<size_t> make_vector(size_t n, size_t x) {
  return std::vector<size_t>(n, x);
}

template <class Tp>
std::vector<Tp> make_vector(size_t n, const Tp& x) {
  return std::vector<Tp>(n, x);
}

template <class... Ts>
auto make_vector(size_t n, size_t m, const Ts&... x) {
  return std::vector<decltype(make_vector(m, x...))>(n, make_vector(m, x...));
}

int main() {
  char buf[16384];
  scanf("%s", buf);
  std::string K = buf;

  size_t D;
  scanf("%zu", &D);

  size_t N = K.length();
  auto dp = make_vector(N+1, 2, D, intmax_t(0));

  dp[0][1][0] = 1;
  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j <= 1; ++j) {
      for (size_t k = 0; k < D; ++k) {
        for (size_t d = 0; d <= 9; ++d) {
          char cd = d + '0';
          if (j && K[i] < cd) break;
          size_t nj = (j && K[i] == cd);
          size_t nk = (k + d) % D;
          (dp[i+1][nj][nk] += dp[i][j][k]) %= mod;
        }
      }
    }
  }

  intmax_t res = (dp[N][0][0] + dp[N][1][0] + mod-1) % mod;
  printf("%jd\n", res);
}
