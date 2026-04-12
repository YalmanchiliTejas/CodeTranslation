#include <cstdio>
#include <cstdint>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <type_traits>

constexpr intmax_t  operator ""_jd(unsigned long long n) { return n; }
constexpr uintmax_t operator ""_ju(unsigned long long n) { return n; }
constexpr size_t    operator ""_zu(unsigned long long n) { return n; }
// constexpr ptrdiff_t operator ""_td(unsigned long long n) { return n; }

template <typename Tp, Tp modulo>
class modint {
  // FIXME to implement with Montgomery multiplication

public:
  using value_type = typename std::make_signed<Tp>::type;

private:
  static constexpr value_type S_mod = modulo;
  value_type M_value = 0;
  value_type M_mod;  // runtime value (used if S_mod == 0)

  static constexpr value_type S_normalize(value_type n) {
    if ((n %= S_mod) < 0) n += S_mod;
    return n;
  }

  static constexpr value_type S_normalize(value_type n, value_type m) {
    if ((n %= m) < 0) n += m;
    return n;
  }

  static constexpr value_type S_inv(value_type n) {
    value_type x = 0;
    value_type y = 1;
    value_type a = n;
    value_type b = S_mod;
    for (value_type u = y, v = x; a;) {
      value_type q = b / a;
      std::swap(x -= q*u, u);
      std::swap(y -= q*v, v);
      std::swap(b -= q*a, a);
    }
    if ((x %= S_mod) < 0) x += S_mod;
    return x;
  }

  static constexpr value_type S_inv(value_type n, value_type m) {
    value_type x = 0;
    value_type y = 1;
    value_type a = n;
    value_type b = m;
    for (value_type u = y, v = x; a;) {
      value_type q = b / a;
      std::swap(x -= q*u, u);
      std::swap(y -= q*v, v);
      std::swap(b -= q*a, a);
    }
    if ((x %= S_mod) < 0) x += S_mod;
    return x;
  }

public:
  modint() = default;
  modint(modint const&) = default;
  modint(modint&&) = default;
  modint(value_type n): M_value(S_normalize(n)) {
    assert(S_mod > 0);
  }
  modint(value_type n, value_type m): M_value(S_normalize(n, m)), M_mod(m) {
    assert(S_mod == 0);
    assert(m > 0);
  }

  modint& operator =(modint const&) = default;
  modint& operator =(modint&&) = default;
  modint& operator =(value_type n) {
    assert(S_mod > 0);
    M_value = S_normalize(n, S_mod);
    return *this;
  }

  modint& operator +=(modint const& other) {
    if (S_mod > 0) {
      if ((M_value += other.M_value) >= S_mod) M_value -= S_mod;
    } else {
      assert(M_mod == other.M_mod);
      if ((M_value += other.M_value) >= M_mod) M_value -= M_mod;
    }
    return *this;
  }
  modint& operator -=(modint const& other) {
    if (S_mod > 0) {
      if ((M_value -= other.M_value) < 0) M_value += S_mod;
    } else {
      assert(M_mod == other.M_mod);
      if ((M_value -= other.M_value) < 0) M_value += M_mod;
    }
    return *this;
  }
  modint& operator *=(modint const& other) {
    if (S_mod > 0) {
      (M_value *= other.M_value) %= S_mod;
    } else {
      assert(M_mod == other.M_mod);
      (M_value *= other.M_value) %= M_mod;
    }
    return *this;
  }
  modint& operator /=(modint const& other) {
    if (S_mod > 0) {
      (M_value *= S_inv(other.M_value)) %= S_mod;
    } else {
      assert(M_mod == other.M_mod);
      (M_value *= S_inv(other.M_value, M_mod)) %= M_mod;
    }
    return *this;
  }

  modint& operator +=(value_type const& n) {
    if (S_mod > 0) return (*this += modint(n));
    return (*this += modint(n, M_mod));
  }
  modint& operator -=(value_type const& n) {
    if (S_mod > 0) return (*this -= modint(n));
    return (*this -= modint(n, M_mod));
  }
  modint& operator *=(value_type const& n) {
    if (S_mod > 0) return (*this *= modint(n));
    return (*this *= modint(n, M_mod));
  }
  modint& operator /=(value_type const& n) {
    if (S_mod > 0) return (*this /= modint(n));
    return (*this /= modint(n, M_mod));
  }

  modint operator +(modint const& other) const { return modint(*this) += other; }
  modint operator -(modint const& other) const { return modint(*this) -= other; }
  modint operator *(modint const& other) const { return modint(*this) *= other; }
  modint operator /(modint const& other) const { return modint(*this) /= other; }
  modint operator +(value_type const& n) const { return modint(*this) += n; }
  modint operator -(value_type const& n) const { return modint(*this) -= n; }
  modint operator *(value_type const& n) const { return modint(*this) *= n; }
  modint operator /(value_type const& n) const { return modint(*this) /= n; }

  modint operator +() const { return *this; }
  modint operator -() const {
    if (S_mod > 0) return modint(0) -= *this;
    return modint(0, M_mod) -= *this;
  }

  modint pow(intmax_t iexp) const {
    modint res = ((S_mod > 0)? modint(1): modint(1, M_mod));
    for (modint dbl = *this; iexp; iexp >>= 1) {
      if (iexp & 1) res *= dbl;
      dbl *= dbl;
    }
    return res;
  }
  modint& pow_eq(intmax_t iexp) { return *this = this->pow(iexp); }

  value_type get() const { return M_value; }
};

template <typename Tp, Tp modulo>
class modtable {
public:
  using size_type = size_t;
  using underlying_type = typename std::make_signed<Tp>::type;
  using value_type = modint<Tp, modulo>;

private:
  std::vector<value_type> M_f, M_fi;

public:
  modtable() = default;
  modtable(modtable const&) = default;
  modtable(modtable&&) = default;

  modtable(underlying_type n): M_f(n+1), M_fi(n+1) {
    assert(modulo > 0);
    M_f[0] = 1;
    for (underlying_type i = 1; i <= n; ++i) M_f[i] = M_f[i-1] * i;
    M_fi[n] = value_type(1) / M_f[n];
    for (underlying_type i = n; i > 0; --i) M_fi[i-1] = M_fi[i] * i;
  }

  modtable(underlying_type n, underlying_type m): M_f(n+1), M_fi(n+1) {
    assert(modulo == 0);
    M_f[0] = underlying_type(1, m);
    for (underlying_type i = 1; i <= n; ++i) M_f[i] = M_f[i-1] * i;
    M_fi[n] = underlying_type(1, m) / M_f[n];
    for (underlying_type i = n; i > 0; --i) M_fi[i-1] = M_fi[i] * i;    
  }

  modtable& operator =(modtable const&) = default;
  modtable& operator =(modtable&&) = default;

  value_type factorial(underlying_type n) const { return M_f[n]; }
  value_type inversed_factorial(underlying_type n) const { return M_fi[n]; }
  value_type choose(underlying_type n, underlying_type r) const {
    // XXX RE if modulo == 0 (runtime mod)
    // XXX implicitly assuming n < modulo
    if (!(0 <= n && 0 <= r && r <= n)) return value_type(0);
    return M_f[n] * M_fi[r] * M_fi[n-r];
  }
};

constexpr intmax_t mod = 1e9+7;
using mi = modint<intmax_t, mod>;

mi pomae(intmax_t N, intmax_t M, intmax_t K) {
  mi res = 0;
  for (intmax_t d = 1; d < M; ++d)
    res += mi(d) * (M-d) * N * N;

  modtable<intmax_t, mod> mt(N*M);
  res *= mt.choose(N*M-2, K-2);
  return res;
}

int main() {
  intmax_t N, M, K;
  scanf("%jd %jd %jd", &N, &M, &K);

  printf("%jd\n", (pomae(N, M, K) + pomae(M, N, K)).get());
}
