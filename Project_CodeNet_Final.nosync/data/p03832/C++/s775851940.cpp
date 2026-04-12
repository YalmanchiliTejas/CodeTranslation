#include <cstdio>
#include <cstdint>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>

constexpr intmax_t  operator ""_jd(unsigned long long n) { return n; }
constexpr uintmax_t operator ""_ju(unsigned long long n) { return n; }
constexpr size_t    operator ""_zu(unsigned long long n) { return n; }
// constexpr ptrdiff_t operator ""_td(unsigned long long n) { return n; }

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

template <typename Tp, Tp Modulo>
class modint {
  // FIXME to implement with Montgomery multiplication

public:
  using value_type = typename std::make_signed<Tp>::type;

private:
  static constexpr value_type S_mod = Modulo;
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
  modint(value_type n): M_value(S_normalize(n)) {}
  modint(value_type n, value_type m): M_value(S_normalize(n, m)), M_mod(m) {}

  modint& operator =(modint const&) = default;
  modint& operator =(modint&&) = default;
  modint& operator =(value_type n) {
    M_value = S_normalize(n, S_mod);
    return *this;
  }

  modint& operator +=(modint const& other) {
    if (S_mod > 0) {
      if ((M_value += other.M_value) >= S_mod) M_value -= S_mod;
    } else {
      if ((M_value += other.M_value) >= M_mod) M_value -= M_mod;
    }
    return *this;
  }
  modint& operator -=(modint const& other) {
    if (S_mod > 0) {
      if ((M_value -= other.M_value) < 0) M_value += S_mod;
    } else {
      if ((M_value -= other.M_value) < 0) M_value += M_mod;
    }
    return *this;
  }
  modint& operator *=(modint const& other) {
    if (S_mod > 0) {
      (M_value *= other.M_value) %= S_mod;
    } else {
      (M_value *= other.M_value) %= M_mod;
    }
    return *this;
  }
  modint& operator /=(modint const& other) {
    if (S_mod > 0) {
      (M_value *= S_inv(other.M_value)) %= S_mod;
    } else {
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

  bool operator ==(modint const& other) const {
    return M_value == other.M_value;
  }
  bool operator ==(value_type const& n) const {
    return M_value == S_normalize(n);
  }
  bool operator !=(modint const& other) const { return !(*this == other); }
  bool operator !=(value_type const& n) const { return !(*this == n); }

  value_type get() const { return M_value; }
  value_type modulo() const { return ((S_mod > 0)? S_mod: M_mod); }

  std::vector<modint> sqrt() const {
    intmax_t const p = ((S_mod > 0)? S_mod: M_mod);
    if (p % 4 == 3) {
      modint r = pow((p+1) / 4);
      if (r * r == *this) return {r, -r};
      return {};
    }

    value_type s = __builtin_ctzll(p-1);
    value_type q = (p-1) >> s;

    modint z;
    for (value_type z0 = 2; z0 < p; ++z0) {
      z = ((S_mod > 0)? modint(z0): modint(z0, M_mod));
      if (z.pow((p-1) / 2) == -1) break;
    }

    value_type m = s;
    modint c = z.pow(q);
    modint t = this->pow(q);
    modint r = this->pow((q+1) / 2);

    while (true) {
      if (t == 0) return {0};
      if (t == 1) return {r, -r};

      value_type i = 0;
      for (auto tt = t; tt != 1; ++i) tt *= tt;
      if (i == m) return {};
      auto b = c;
      for (value_type j = 0; j < m-i-1; ++j) b *= b;
      m = i;
      c = b * b;
      t *= c;
      r *= b;
    }
  }
};

template <typename T1, typename T2, T2 modulo>
modint<T2, modulo> operator +(T1 const& lhs, modint<T2, modulo> const& rhs) {
  if (modulo > 0) return modint<T2, modulo>(lhs) + rhs;
  return modint<T2, modulo>(lhs, rhs.modulo()) + rhs;
}
template <typename T1, typename T2, T2 modulo>
modint<T2, modulo> operator -(T1 const& lhs, modint<T2, modulo> const& rhs) {
  if (modulo > 0) return modint<T2, modulo>(lhs) - rhs;
  return modint<T2, modulo>(lhs, rhs.modulo()) - rhs;
}
template <typename T1, typename T2, T2 modulo>
modint<T2, modulo> operator *(T1 const& lhs, modint<T2, modulo> const& rhs) {
  if (modulo > 0) return modint<T2, modulo>(lhs) * rhs;
  return modint<T2, modulo>(lhs, rhs.modulo()) * rhs;
}
template <typename T1, typename T2, T2 modulo>
modint<T2, modulo> operator /(T1 const& lhs, modint<T2, modulo> const& rhs) {
  if (modulo > 0) return modint<T2, modulo>(lhs) / rhs;
  return modint<T2, modulo>(lhs, rhs.modulo()) / rhs;
}
template <typename T1, typename T2, T2 modulo>
bool operator ==(T1 const& lhs, modint<T2, modulo> const& rhs) {
  return rhs == lhs;
}
template <typename T1, typename T2, T2 modulo>
bool operator !=(T1 const& lhs, modint<T2, modulo> const& rhs) {
  return !(lhs == rhs);
}

template <typename Tp, Tp Modulo>
class modtable {
public:
  using size_type = size_t;
  using underlying_type = typename std::make_signed<Tp>::type;
  using value_type = modint<Tp, Modulo>;

private:
  std::vector<value_type> M_f, M_fi;

public:
  modtable() = default;
  modtable(modtable const&) = default;
  modtable(modtable&&) = default;

  modtable(underlying_type n): M_f(n+1), M_fi(n+1) {
    assert(Modulo > 0);
    M_f[0] = 1;
    for (underlying_type i = 1; i <= n; ++i) M_f[i] = M_f[i-1] * i;
    M_fi[n] = value_type(1) / M_f[n];
    for (underlying_type i = n; i > 0; --i) M_fi[i-1] = M_fi[i] * i;
  }

  modtable(underlying_type n, underlying_type m): M_f(n+1), M_fi(n+1) {
    assert(Modulo == 0);
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
    // XXX implicitly assuming n < Modulo
    if (!(0 <= n && 0 <= r && r <= n)) {
      if (Modulo == 0) return value_type(0, M_f[0].Modulo());
      return value_type(0);
    }
    return M_f[n] * M_fi[r] * M_fi[n-r];
  }
};

constexpr intmax_t mod = 1'000'000'007;  // '
using mi = modint<intmax_t, mod>;

int main() {
  size_t n, a, b, c, d;
  scanf("%zu %zu %zu %zu %zu", &n, &a, &b, &c, &d);

  modtable<intmax_t, mod> mt(n+1);
  auto dp = make_vector<mi>({b+1, n+1}, mi(0));
  dp[a-1][0] = 1;
  for (size_t i = a; i <= b; ++i) {
    for (size_t j = 0; j <= n; ++j) {
      dp[i][j] = dp[i-1][j];
      for (size_t k = c; k <= d; ++k) {
        if (!(j-i*k <= n)) break;
        dp[i][j] += dp[i-1][j-i*k]
          * mt.factorial(n-(j-i*k))
          * mt.inversed_factorial(n-j)
          * mt.inversed_factorial(i).pow(k)
          * mt.inversed_factorial(k);
      }
    }
  }

  printf("%jd\n", dp[b][n].get());
}
