#line 1 "F.cpp"
#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

#line 1 "~/git/library/utility/literals.cpp"



/**
 * @brief ユーザ定義リテラル
 * @author えびちゃん
 */

#include <cstddef>
#line 11 "~/git/library/utility/literals.cpp"

constexpr intmax_t  operator ""_jd(unsigned long long n) { return n; }
constexpr uintmax_t operator ""_ju(unsigned long long n) { return n; }
constexpr size_t    operator ""_zu(unsigned long long n) { return n; }
constexpr ptrdiff_t operator ""_td(unsigned long long n) { return n; }


#line 1 "~/git/library/utility/make/vector.cpp"
/**
 * @brief 多次元 vector の作成
 * @author えびちゃん
 */

#ifndef H_make_vector
#define H_make_vector

#line 10 "~/git/library/utility/make/vector.cpp"
#include <type_traits>
#line 12 "~/git/library/utility/make/vector.cpp"

namespace detail {
  template <typename Tp, size_t Nb>
  auto make_vector(std::vector<size_t>& sizes, Tp const& x) {
    if constexpr (Nb == 1) {
      return std::vector(sizes[0], x);
    } else {
      size_t size = sizes[Nb-1];
      sizes.pop_back();
      return std::vector(size, make_vector<Tp, Nb-1>(sizes, x));
    }
  }
}  // detail::

template <typename Tp, size_t Nb>
auto make_vector(size_t const(&sizes)[Nb], Tp const& x = Tp()) {
  std::vector<size_t> s(Nb);
  for (size_t i = 0; i < Nb; ++i) s[i] = sizes[Nb-i-1];
  return detail::make_vector<Tp, Nb>(s, x);
}

#endif  /* !defined(H_make_vector) */
#line 8 "F.cpp"

int main() {
  size_t n;
  scanf("%zu", &n);

  std::vector<intmax_t> a(n);
  for (auto& ai: a) scanf("%jd", &ai);

  intmax_t const inf = -1e17;
  auto dp = make_vector({n+1, 3_zu}, inf);
  // dp[0][0] = 0;
  dp[1][0] = a[0];
  dp[2][1] = a[1];
  if (n >= 3) dp[3][2] = a[2];

  for (size_t i = 1; i < n; ++i) {
    for (size_t j = 0; j <= 2; ++j) {
      dp[i+1][j] = std::max(dp[i+1][j], dp[i-1][j] + a[i]);
      if (i-2 < n && j < 2) {
        dp[i+1][j+1] = std::max(dp[i+1][j+1], dp[i-2][j] + a[i]);
      }
      if (i-3 < n && j < 1) {
        dp[i+1][j+2] = std::max(dp[i+1][j+2], dp[i-3][j] + a[i]);
      }
    }
  }

  if (n % 2 == 0) {
    printf("%jd\n", std::max({dp[n][1], dp[n-1][0]}));
  } else {
    printf("%jd\n", std::max({dp[n][2], dp[n-1][1], dp[n-2][0]}));
  }
}
