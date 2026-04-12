/**
 * @brief ユーザ定義リテラル
 * @author えびちゃん
 */

#ifndef H_int_literals
#define H_int_literals

#include <cstddef>
#include <cstdint>

constexpr intmax_t  operator ""_jd(unsigned long long n) { return n; }
constexpr uintmax_t operator ""_ju(unsigned long long n) { return n; }
constexpr size_t    operator ""_zu(unsigned long long n) { return n; }
constexpr ptrdiff_t operator ""_td(unsigned long long n) { return n; }

#endif  /* !defined(H_int_literals) */

/**
 * @brief 多次元 vector の作成
 * @author えびちゃん
 */

#ifndef H_make_vector
#define H_make_vector

#include <cstddef>
#include <type_traits>
#include <vector>

namespace detail {
  template <typename Tp, size_t N>
  std::vector<Tp> make_vector(
      std::vector<size_t>& sizes,
      typename std::enable_if<(N == 1), Tp const&>::type x
  ) {
    return std::vector<Tp>(sizes[0], x);
  }
  template <typename Tp, size_t N>
  auto make_vector(
      std::vector<size_t>& sizes,
      typename std::enable_if<(N > 1), Tp const&>::type x
  ) {
    size_t size = sizes[N-1];
    sizes.pop_back();
    return std::vector<decltype(make_vector<Tp, N-1>(sizes, x))>(
        size, make_vector<Tp, N-1>(sizes, x)
    );
  }
}  // detail::

template <typename Tp, size_t N>
auto make_vector(size_t const(&sizes)[N], Tp const& x = Tp()) {
  std::vector<size_t> s(N);
  for (size_t i = 0; i < N; ++i) s[i] = sizes[N-i-1];
  return detail::make_vector<Tp, N>(s, x);
}

#endif  /* !defined(H_make_vector) */

#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <array>

int main() {
  char buf[128];
  scanf("%s", buf);
  std::string s = buf;
  size_t k;
  scanf("%zu", &k);
  size_t n = s.length();

  size_t const loose = 0;
  size_t const tight = 1;
  std::array<size_t, 2> const tightness{{loose, tight}};

  auto dp = make_vector({n+1, k+1, 2_zu}, 0_jd);
  dp[0][0][tight] = 1;
  for (size_t i = 0; i < n; ++i) {
    for (size_t t: tightness) {
      for (size_t j = 0; j <= k; ++j) {
        for (int c = '0'; c <= '9'; ++c) {
          if (t == tight && s[i] < c) break;
          size_t nt = (t == tight && s[i] == c)? tight: loose;
          size_t nj = ((c == '0')? j: j+1);
          if (nj > k) continue;
          dp[i+1][nj][nt] += dp[i][j][t];
        }
      }
    }
  }

  printf("%jd\n", (dp[n][k][loose] + dp[n][k][tight]));
}
