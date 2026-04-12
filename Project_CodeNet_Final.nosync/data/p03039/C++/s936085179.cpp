#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>

template <class Tp>
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

template <class Tp>
Tp modinv(Tp a, Tp mod) {
  Tp x, y;
  gcd(a, mod, x, y);
  x %= mod;
  if (x < 0) x += mod;
  return x;
}

template <class Tp>
Tp modadd(Tp a, Tp b, Tp mod) {
  a += b % mod;
  if (a < 0) a += mod;
  if (a >= mod) a -= mod;
  return a;
}

template <class Tp>
Tp modadd(const std::initializer_list<Tp>& adds, Tp mod) {
  Tp res = 0;
  for (const auto& add: adds) {
    res += add % mod;
    if (res < 0) res += mod;
    if (res >= mod) res -= mod;
  }
  return res;
}

template <class Tp>
Tp modsub(Tp a, Tp b, Tp mod) {
  a -= b % mod;
  if (a < 0) a += mod;
  if (a >= mod) a -= mod;
  return a;
}

template <class Tp>
Tp modmul(const std::initializer_list<Tp>& muls, Tp mod) {
  Tp res = 1;
  for (const auto& mul: muls) (res *= mul) %= mod;
  return res;
}

template <class Tp>
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
    intmax_t res = fact[n] * fact_inv[r] % mod;
    (res *= fact_inv[n-r]) %= mod;
    return res;
  }
};

constexpr intmax_t mod = 1e9+7;

intmax_t pomae(intmax_t N, intmax_t M, intmax_t K) {
  intmax_t res = 0;
  for (intmax_t d = 1; d < M; ++d) {
    (res += modmul({d, (M-d), N, N}, mod)) %= mod;
  }
  modchoose ncr(N*M, mod);
  (res *= ncr(N*M-2, K-2)) %= mod;
  return res;
}

int main() {
  intmax_t N, M, K;
  scanf("%jd %jd %jd", &N, &M, &K);

  intmax_t res = 0;
  (res += pomae(N, M, K)) %= mod;
  (res += pomae(M, N, K)) %= mod;

  printf("%jd\n", res);
}
