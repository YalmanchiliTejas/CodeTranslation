#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

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
  size_t N;
  scanf("%zu", &N);

  std::vector<intmax_t> a(N);
  for (auto& ai: a) scanf("%jd", &ai);

  auto dp = make_vector(N, N, intmax_t(-1e13));

  for (size_t i = 0; i < N; ++i)
    dp[i][i] = a[i];

  for (size_t w = 1; w < N; ++w)
    for (size_t i = 0; i+w < N; ++i)
      dp[i][i+w] = std::max(a[i]-dp[i+1][i+w], a[i+w]-dp[i][i+w-1]);

  printf("%jd\n", dp[0][N-1]);
}
