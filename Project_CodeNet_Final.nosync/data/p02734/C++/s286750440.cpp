#ifndef DEBUG
#  define NDEBUG
#endif
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <utility>
#include <type_traits>
#include <limits>
#include <cassert>
#include <numeric>
#include <vector>
#include <array>

using namespace std;

// template {{{
// misc {{{
using Z = long long;
[[maybe_unused]]
constexpr Z INF = numeric_limits<Z>::max() / 3;
// }}}

// debug {{{
template <class T>
using enable_if_sequence_t = enable_if_t<
  is_same<
    typename iterator_traits<
      typename remove_cv_t<remove_reference_t<T>>::iterator
    >::iterator_category,
    random_access_iterator_tag>{}>;
#ifdef NDEBUG
# define dump(x)
# define debug if (0)
template <class T>
inline T&& ix(T&& value) { return value; }
template <class T, class Index, class... Indices, class = enable_if_sequence_t<T>>
inline auto&& ix(T&& container, Index index, Indices... indices) {
  return ix(container[index], indices...);
}
#else
# define dump(x) do { \
    cerr << "\e[33m[dump: " << __LINE__ << "] " << (#x) << " = " << x << "\e[0m" << endl; \
  } while (0);
# define debug
template <class T>
inline auto&& ix_impl([[maybe_unused]] int line, [[maybe_unused]] const char* code, T&& value) {
  return value;
}
template <class T, class Index, class... Indices, class = enable_if_sequence_t<T>>
inline auto&& ix_impl(int line, const char* code, T&& container, Index index, Indices... indices) {
  if (index < 0) {
    cerr << "\e[31mix: negative index at line " << line << ", ix(" << code << ")\n"
      << "index = " << index << "\e[0m" << endl;
    exit(1);
  }
  int size = distance(begin(container), end(container));
  if (index >= size) {
    cerr << "\e[31mix: index out of range at line " << line << ", ix(" << code << ")\n"
      << "index = " << index << " whereas size = " << size << "\e[0m" << endl;
    exit(1);
  }
  return ix_impl(line, code, container[index], indices...);
}
#define ix(...) ix_impl(__LINE__, #__VA_ARGS__, __VA_ARGS__)
#endif
// }}}

// IO {{{
template <class T, class U>
ostream& operator<< (ostream& os, pair<T, U> p) {
  os << '(' << p.first << ", " << p.second << ')';
  return os;
}
template <class T, class U>
istream& operator>> (istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
false_type is_container_impl(...);
template <class T, class = typename T::iterator>
true_type is_container_impl(T);
template <class T>
struct is_container : decltype(is_container_impl<T>(declval<T>())) {};
template <>
struct is_container <string> : std::false_type {};
template <class Container, class = enable_if_t<is_container<Container>{}>>
istream& operator>> (istream& is, Container& cont) {
  for (auto& v : cont) is >> v;
  return is;
}
template <class Container, class = enable_if_t<is_container<Container>{}>>
ostream& operator<< (ostream& os, Container const& cont) {
  bool first = true;
  constexpr char sep =
    is_container<typename Container::value_type>{} ? '\n' : ' ';
  for (auto const& v : cont) {
    if (!first) {
      os << sep;
    }
    first = false;
    os << v;
  }
  return os;
}
// }}}
// }}}


// bpow {{{
template <class T>
T bpow(T x, int k) {
  if (k == 0) return T(1);
  auto const& prev = bpow(x, k / 2);
  if (k % 2 == 0) return prev * prev;
  else return prev * prev * x;
}
// }}}
// {{{ extgcd
template <class T>
struct extgcd_solution {
  T gcd, x, y;
};

template <class T = Z>
constexpr extgcd_solution<T> extgcd(T a, T b) {
  if (b == 0) return { a, 1, 0 };
  if (a < b) {
    auto res = extgcd(b, a);
    return { res.gcd, res.y, res.x };
  }
  auto prev = extgcd(b, a % b);
  return {
    prev.gcd,
    prev.y,
    prev.x - prev.y * (a / b)
  };
}
// }}}
// Mod {{{
template <class T = Z, T mod = 1000000007>
class Mod {
  private:
    T value;
  public:
    constexpr Mod(): value(0) {}
    constexpr Mod(T original): value(
        original >= 0
        ? original % mod
        : ((1 - original / mod) * mod + original)) {}
    inline constexpr operator T() const {
      return value;
    }
    inline constexpr Mod inv() const {
      auto&& res = extgcd(value, mod);
      assert(res.gcd == 1);
      return Mod(res.x);
    }
    inline constexpr Mod operator+ (Mod const m) const {
      return Mod(value + m.value);
    }
    inline constexpr Mod operator- (Mod const m) const {
      return Mod(value - m.value);
    }
    inline constexpr Mod operator* (Mod const m) const {
      long long prod = value;
      prod *= m.value;
      prod %= mod;
      return Mod(static_cast<T>(prod));
    }
    inline constexpr Mod operator/ (Mod const m) const {
      return *this * m.inv();
    }
    inline constexpr Mod operator+ (T m) const {
      return Mod(value + (m % mod));
    }
    inline constexpr Mod operator- (T m) const {
      return Mod(value - m);
    }
    inline constexpr Mod operator* (T m) const {
      long long prod = value;
      prod *= m % mod;
      prod %= mod;
      return Mod(static_cast<T>(prod));
    }
    inline constexpr Mod operator/ (T m) const {
      return *this * Mod(m).inv();
    }
    inline constexpr Mod pow(int k) const {
      return k >= 0
        ? bpow(*this, k)
        : bpow(inv(), -k);
    }
    inline ostream& operator<< (ostream& os) {
      os << '[' << value << ']';
      return os;
    }
    inline istream& operator>> (istream& is) {
      is >> value;
      return is;
    }
};

template <class T, T mod>
inline constexpr Mod<T, mod> operator+ (T n, Mod<T, mod> m) {
  return m + n;
}
template <class T, T mod>
inline constexpr Mod<T, mod> operator- (T n, Mod<T, mod> m) {
  return Mod<T, mod>(n) - m;
}
template <class T, T mod>
inline constexpr Mod<T, mod> operator* (T n, Mod<T, mod> m) {
  return m * n;
}
template <class T, T mod>
inline constexpr Mod<T, mod> operator/ (T n, Mod<T, mod> m) {
  return Mod<T, mod>(n) / m;
}
template <class T, T mod, class R>
inline Mod<T, mod>& operator+= (Mod<T, mod>& m, R rhs) {
  return m = m + rhs;
}
template <class T, T mod, class R>
inline Mod<T, mod>& operator-= (Mod<T, mod>& m, R rhs) {
  return m = m - rhs;
}
template <class T, T mod, class R>
inline Mod<T, mod>& operator*= (Mod<T, mod>& m, R rhs) {
  return m = m * rhs;
}
template <class T, T mod, class R>
inline Mod<T, mod>& operator/= (Mod<T, mod>& m, R rhs) {
  return m = m / rhs;
}
// }}}

using MZ = Mod<Z, 998244353>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  Z N, S;
  cin >> N >> S;
  vector<Z> As(N);
  cin >> As;
  vector<vector<MZ>> dp(N + 1, vector<MZ>(S + 1, 0));
  for (auto i = 0; i < N; i++) {
    ix(dp, i, 0) += 1ll;
    for (auto j = 0; j <= S; j++) {
      ix(dp, i + 1, j) += ix(dp, i, j);
      if (ix(As, i) + j > S) continue;
      ix(dp, i + 1, j + ix(As, i)) += ix(dp, i, j);
    }
  }
  dump(dp);
  MZ ans = 0;
  for (auto i = 0; i <= N; i++) {
    ans += ix(dp, i, S);
  }
  cout << ans << '\n';
}

