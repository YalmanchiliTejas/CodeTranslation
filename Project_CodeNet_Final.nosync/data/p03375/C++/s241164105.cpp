#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>

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
auto make_vector(size_t const(&sizes)[N], Tp const& x) {
  std::vector<size_t> s(N);
  for (size_t i = 0; i < N; ++i) s[i] = sizes[N-i-1];
  return detail::make_vector<Tp, N>(s, x);
}

constexpr intmax_t  operator ""_jd(unsigned long long n) { return n; }
constexpr uintmax_t operator ""_ju(unsigned long long n) { return n; }
constexpr size_t    operator ""_zu(unsigned long long n) { return n; }
// constexpr ptrdiff_t operator ""_td(unsigned long long n) { return n; }

template <typename Tp>
Tp gcd(Tp a, Tp b, Tp& x, Tp& y) {
  x = Tp(0);
  y = Tp(1);
  for (Tp u = y, v = x; a;) {
    Tp q = b/a;
    std::swap(x -= q*u, u);
    std::swap(y -= q*v, v);
    std::swap(b -= q*a, a);
  }
  return b;
}

template <typename Tp>
Tp modinv(Tp a, Tp mod) {
  Tp x, y;
  gcd(a, mod, x, y);
  x %= mod;
  if (x < 0) x += mod;
  return x;
}

template <typename Tp>
Tp modadd(Tp a, Tp b, Tp mod) {
  a += b % mod;
  if (a < 0) a += mod;
  if (a >= mod) a -= mod;
  return a;
}

template <typename Tp>
Tp modadd(std::initializer_list<Tp> const& adds, Tp mod) {
  Tp res = 0;
  for (auto const& add: adds) {
    res += add % mod;
    if (res < 0) res += mod;
    if (res >= mod) res -= mod;
  }
  return res;
}

template <typename Tp>
Tp modsub(Tp a, Tp b, Tp mod) {
  a -= b % mod;
  if (a < 0) a += mod;
  if (a >= mod) a -= mod;
  return a;
}

template <typename Tp>
Tp modmul(std::initializer_list<Tp> const& muls, Tp mod) {
  Tp res = 1;
  for (auto const& mul: muls) (res *= mul) %= mod;
  return res;
}

template <typename Tp>
Tp modpow(Tp base, intmax_t iexp, Tp mod) {
  Tp res = 1;
  for (Tp dbl = base; iexp; iexp >>= 1) {
    if (iexp & 1) res = res * dbl % mod;
    dbl = dbl * dbl % mod;
  }
  return res;
}

class modchoose {
  std::vector<intmax_t> fact, fact_inv;
  intmax_t mod;

public:
  modchoose(intmax_t N, intmax_t mod): mod(mod) {
    fact.resize(N+1);
    fact_inv.resize(N+1);
    fact[0] = 1;
    for (intmax_t i = 1; i <= N; ++i)
      fact[i] = fact[i-1] * i % mod;

    fact_inv[N] = modinv(fact[N], mod);
    for (intmax_t i = N; i--;)
      fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
  }

  intmax_t operator ()(intmax_t n, intmax_t r) const {
    if (!(0 <= r && r <= n && 0 <= n)) return 0;
    intmax_t res = fact[n] * fact_inv[r] % mod;
    (res *= fact_inv[n-r]) %= mod;
    return res;
  }
};

int main() {
  intmax_t n, m;
  scanf("%jd %jd", &n, &m);

  std::vector<std::vector<intmax_t>> dp(n+1, {1_jd, 0_jd});
  for (intmax_t i = 1; i <= n; ++i) {
    dp[i].resize(i+2, 0_jd);
    for (intmax_t j = 1; j <= i; ++j)
      (dp[i][j] += dp[i-1][j-1] + dp[i-1][j] * (j+1)) %= m;
  }

  modchoose mc(n, m);

  intmax_t res = 0;
  for (intmax_t i = 0; i <= n; ++i) {
    intmax_t cur = 0;
    for (intmax_t j = 0; j <= i; ++j) {
      (cur += modpow(2_jd, (n-i)*j, m) * dp[i][j]) %= m;
    }
    (cur *= modpow(2_jd, modpow(2_jd, n-i, m-1), m)) %= m;
    (cur *= mc(n, i)) %= m;
    if (i % 2) cur = (m-cur) % m;
    (res += cur) %= m;
  }

  printf("%jd\n", res);
}
