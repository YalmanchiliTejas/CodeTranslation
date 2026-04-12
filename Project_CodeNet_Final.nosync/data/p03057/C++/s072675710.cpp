// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
#include<bitset>
#include<cstdlib>
// #include<deque>
// #include<multiset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

// #undef DEBUG
// #define DEBUG
// DEBUG {{{
#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <valarray>
#include <vector>
template < int n, class... T >
typename std::enable_if< (n >= sizeof...(T)) >::type __output_tuple(
    std::ostream &, std::tuple< T... > const &) {}
template < int n, class... T >
typename std::enable_if< (n < sizeof...(T)) >::type __output_tuple(
    std::ostream &os, std::tuple< T... > const &t) {
  os << (n == 0 ? "" : ", ") << std::get< n >(t);
  __output_tuple< n + 1 >(os, t);
}
template < class... T >
std::ostream &operator<<(std::ostream &os, std::tuple< T... > const &t) {
  os << "(";
  __output_tuple< 0 >(os, t);
  os << ")";
  return os;
}
template < class T, class U >
std::ostream &operator<<(std::ostream &os, std::pair< T, U > const &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template < class T >
std::ostream &operator<<(std::ostream &os, const std::stack< T > &a) {
  os << "{";
  for(auto tmp = a; tmp.size(); tmp.pop())
    os << (a.size() == tmp.size() ? "" : ", ") << tmp.top();
  os << "}";
  return os;
}
template < class T, class Container, class Compare >
std::ostream &operator<<(std::ostream &os,
    std::priority_queue< T, Container, Compare > a) {
  os << "{ (top) ";
  while(a.size()) os << a.top() << (a.size() == 1 ? "" : ", "), a.pop();
  os << " }";
  return os;
}
template < class T, class Container >
std::ostream &operator<<(std::ostream &os, std::queue< T, Container > a) {
  os << "{ ";
  while(a.size()) os << a.front() << (a.size() == 1 ? "" : ", "), a.pop();
  os << " }";
  return os;
}
#ifdef DEBUG
#if !defined(DEBUG_OUT)
// #define DEBUG_OUT std::cerr
#endif
#define dump(...)                                                                \
  [&]() {                                                                        \
    auto __debug_tap = std::make_tuple(__VA_ARGS__);                             \
    DEBUG_OUT << "[" << __LINE__ << "] " << #__VA_ARGS__ << " = " << __debug_tap \
    << std::endl;                                                      \
  }()
template < class T >
inline void dump2D(T &d, size_t sizey, size_t sizex) {
  for(size_t i = 0; i < sizey; i++) {
    DEBUG_OUT << "\t";
    for(size_t j = 0; j < sizex; j++)
      DEBUG_OUT << d[i][j] << (j + 1 == sizex ? "" : "\t");
    DEBUG_OUT << std::endl;
  }
}
template < class T >
inline void dump1D(T &d, size_t sizey) {
  for(size_t i = 0; i < sizey; i++) {
    DEBUG_OUT << d[i] << (i + 1 == sizey ? "" : " ");
  }
  DEBUG_OUT << std::endl;
}
template <
class T, class = typename std::iterator_traits< decltype(begin(T())) >::value_type,
      class = typename std::enable_if< !std::is_same< T, std::string >::value >::type >
      std::ostream &operator<<(std::ostream &os, const T &a) {
        os << "{";
        for(auto ite = begin(a); ite != end(a); ++ite)
          os << (ite == begin(a) ? "" : ", ") << *ite;
        os << "}";
        return os;
      }
#else
#define dump(...) (42)
#define dump2D(...) (42)
#define dump1D(...) (42)
template <
class T, class = typename std::iterator_traits< decltype(begin(T())) >::value_type,
      class = typename std::enable_if< !std::is_same< T, std::string >::value >::type >
      std::ostream &operator<<(std::ostream &os, const T &a) {
        for(auto ite = begin(a); ite != end(a); ++ite)
          os << (ite == begin(a) ? "" : " ") << *ite;
        return os;
      }
#endif
// }}}


/// --- Modulo Integer {{{ ///
#include <ostream>
template < long long mod = static_cast< long long >(1e9 + 7) >
struct ModuloInteger {
  static_assert(mod > 0, "mod must be positive");
  static_assert(mod <= 3037000499, "mod is too big");
  using integer = long long;
  static ModuloInteger unused;
  // math {{{
  static inline integer extgcd(integer a, integer b, integer &x, integer &y) {
    integer d;
    return b == 0 ? (x = a < 0 ? -1 : 1, y = 0, a < 0 ? -a : a)
      : (d = extgcd(b, a % b, y, x), y -= a / b * x, d);
  }
  static inline integer modinv(integer a) {
    integer x = 0, y = 0;
    extgcd(a, mod, x, y);
    if(x < 0)
      x += mod;
    else if(x == mod)
      x = 0;
    return x;
  }
  static inline integer modpow(integer a, long long b) {
    if(b < 0) b = -b, a = modinv(a);
    integer r = 1;
    a %= mod;
    while(b) {
      if(b & 1) r = r * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return r;
  }
  // }}}

  integer val;
  constexpr ModuloInteger() : val(0) {}
  constexpr ModuloInteger(integer t) {
    val = t % mod;
    if(val < 0) val += mod;
  }

private:
  // strict constructor
  constexpr ModuloInteger(integer t, int) : val(t) {}

public:
  template < class T >
    explicit operator T() {
      return T(val);
    }
  // operator bool() { return bool(val); }
  // ModuloInteger <arithmetic-operator>[=] ModuloInteger {{{
  ModuloInteger operator+(ModuloInteger const &rhs) const {
    ModuloInteger tmp = *this;
    tmp += rhs;
    return tmp;
  }
  ModuloInteger operator-(ModuloInteger const &rhs) const {
    ModuloInteger tmp = *this;
    tmp -= rhs;
    return tmp;
  }
  ModuloInteger operator*(ModuloInteger const &rhs) const {
    ModuloInteger tmp = *this;
    tmp *= rhs;
    return tmp;
  }
  ModuloInteger operator/(ModuloInteger const &rhs) const {
    ModuloInteger tmp = *this;
    tmp /= rhs;
    return tmp;
  }
  ModuloInteger &operator+=(ModuloInteger const &rhs) {
    val = val + rhs.val;
    if(val >= mod) val -= mod;
    return *this;
  }
  ModuloInteger &operator-=(ModuloInteger const &rhs) { return *this += -rhs; }
  ModuloInteger &operator*=(ModuloInteger const &rhs) {
    val = val * rhs.val % mod;
    return *this;
  }
  ModuloInteger &operator/=(ModuloInteger const &rhs) { return *this *= rhs.inv(); }
  // }}}
  // increment, decrement {{{
  ModuloInteger operator++(int) {
    ModuloInteger tmp = *this;
    val = val + 1;
    if(val >= mod) val = 0;
    return tmp;
  }
  ModuloInteger operator--(int) {
    ModuloInteger tmp = *this;
    val = val == 0 ? mod - 1 : val - 1;
    return tmp;
  }
  ModuloInteger &operator++() {
    val = val + 1;
    if(val >= mod) val = 0;
    return *this;
  }
  ModuloInteger &operator--() {
    val = val == 0 ? mod - 1 : val - 1;
    return *this;
  }
  // }}}
  ModuloInteger operator-() const { return ModuloInteger(val == 0 ? 0 : mod - val, 0); }
  // ModuloInteger <arithmetic-operator>[=] T {{{
  template < typename T >
    ModuloInteger operator+(T const &rhs) const {
      return ModuloInteger(val + rhs % mod);
    }
  template < typename T >
    ModuloInteger operator-(T const &rhs) const {
      return ModuloInteger(mod + val - rhs % mod);
    }
  template < typename T >
    ModuloInteger operator*(T const &rhs) const {
      return ModuloInteger(val * (rhs % mod));
    }
  template < typename T >
    ModuloInteger operator/(T const &rhs) const {
      return ModuloInteger(val * modinv(rhs));
    }
  template < typename T >
    ModuloInteger &operator+=(T const &rhs) {
      val = (mod + val + rhs % mod) % mod;
      return *this;
    }
  template < typename T >
    ModuloInteger &operator-=(T const &rhs) {
      val = (mod + val - rhs % mod) % mod;
      return *this;
    }
  template < typename T >
    ModuloInteger &operator*=(T const &rhs) {
      val = val * (mod + rhs % mod) % mod;
      return *this;
    }
  template < typename T >
    ModuloInteger &operator/=(T const &rhs) {
      val = val * modinv(rhs) % mod;
      return *this;
    }
  // }}}
  ModuloInteger inv() const { return ModuloInteger(modinv(val), 0); }
  ModuloInteger operator~() const { return inv(); }
  friend std::ostream &operator<<(std::ostream &os, ModuloInteger const &mv) {
    os << mv.val;
    return os;
  }
  // equality operator {{{
  ModuloInteger operator==(const ModuloInteger &a) const { return val == a.val; }
  ModuloInteger operator!=(const ModuloInteger &a) const { return val != a.val; }
  ModuloInteger operator==(const integer &a) const { return val == ModuloInteger(a); }
  ModuloInteger operator!=(const integer &a) const { return val != ModuloInteger(a); }
  // }}}
  // T <arithmetic-operator> ModuloInteger {{{
  friend constexpr ModuloInteger operator+(integer a, ModuloInteger const &mv) {
    return ModuloInteger(a % mod + mv.val);
  }
  friend constexpr ModuloInteger operator-(integer a, ModuloInteger const &mv) {
    return ModuloInteger(a % mod - mv.val);
  }
  friend constexpr ModuloInteger operator*(integer a, ModuloInteger const &mv) {
    return ModuloInteger((mod + a % mod) * mv.val % mod, 0);
  }
  friend constexpr ModuloInteger operator/(integer a, ModuloInteger const &mv) {
    return ModuloInteger((mod + a % mod) * modinv(mv.val) % mod, 0);
  }
  // }}}
  // power {{{
  ModuloInteger operator^(integer x) const { return pow(*this, x); }
  ModuloInteger &operator^=(integer x) {
    val = modpow(val, x);
    return *this;
  }
  friend ModuloInteger pow(ModuloInteger x, integer y) {
    return ModuloInteger(modpow(x.val, y), 0);
  }
  // }}}
};
template < long long mod >
ModuloInteger< mod > ModuloInteger< mod >::unused(mod, 0);
/// }}}--- ///

using modint = ModuloInteger<>;


// LazySegmentTree( size [, initial] )
// LazySegmentTree( <data> )
/// --- LazySegmentTree {{{ ///
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <vector>
template < class M_act >
struct LazySegmentTree {
public:
  using Monoid = typename M_act::Monoid;
  using X = typename Monoid::T;
  using M = typename M_act::M;

private:
  size_t n;
  int h;
  vector< X > data;
  vector< M > lazy;
  vector< size_t > nodeLength;
  // call before use data[i]
  void eval(size_t i) {
    if(lazy[i] == M_act::identity()) return;
    data[i] = M_act::actInto(lazy[i], nodeLength[i], data[i]);
    if(i < n) {
      lazy[i * 2] = M_act::op(lazy[i], lazy[i * 2]);
      lazy[i * 2 + 1] = M_act::op(lazy[i], lazy[i * 2 + 1]);
    }
    lazy[i] = M_act::identity();
  }
  // call before use seg[i] = data[i + n]
  void evalDown(size_t i) {
    i += n;
    for(int j = h - 1; j >= 0; j--) eval(i >> j);
  }
  // call after touch seg[i] = data[i + n]
  void propUp(size_t i) {
    i += n;
    while(i >>= 1)
      eval(i * 2), eval(i * 2 + 1), data[i] = Monoid::op(data[i * 2], data[i * 2 + 1]);
  }

public:
  LazySegmentTree() : n(0) {}
  LazySegmentTree(size_t n, X initial = Monoid::identity()) : n(n) {
    if(n > 0) {
      h = 1;
      while(1u << h < n) h++;
      data.resize(2 * n, initial);
      lazy.resize(2 * n, M_act::identity());
      nodeLength.resize(2 * n, 1);
      for(size_t i = n - 1; i > 0; i--) // fill from deep
        data[i] = Monoid::op(data[i * 2], data[i * 2 + 1]),
          nodeLength[i] = nodeLength[i * 2] + nodeLength[i * 2 + 1];
    }
  }
  template < class InputIter, class = typename iterator_traits< InputIter >::value_type >
    LazySegmentTree(InputIter first, InputIter last)
    : LazySegmentTree(distance(first, last)) {
      if(n > 0) {
        copy(first, last, begin(data) + n);
        for(size_t i = n - 1; i > 0; i--) // fill from deep
          data[i] = Monoid::op(data[i * 2], data[i * 2 + 1]);
      }
    }
  LazySegmentTree(vector< X > v) : LazySegmentTree(v.begin(), v.end()) {}
  LazySegmentTree(initializer_list< X > v) : LazySegmentTree(v.begin(), v.end()) {}
  void act(int l, int r, const M &m) {
    if(l < 0) l = 0;
    if(l >= r) return;
    if(r > (int) n) r = n;
    evalDown(l);
    evalDown(r - 1);
    int tl = l, tr = r;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if(l & 1) eval(l), lazy[l] = m, eval(l), l++;
      if(r & 1) --r, eval(r), lazy[r] = m, eval(r);
    }
    propUp(tl);
    propUp(tr - 1);
  }
  void set(size_t i, const X &x) {
    assert(i < n);
    evalDown(i);
    data[i + n] = x;
    propUp(i);
  }
  X get(size_t i) {
    assert(i < n);
    evalDown(i);
    return data[i + n];
  }
  X fold(int l, int r) {
    if(l < 0) l = 0;
    if(l >= r) return Monoid::identity();
    if(r > (int) n) r = n;
    evalDown(l);
    evalDown(r - 1);
    X tmpL = Monoid::identity(), tmpR = Monoid::identity();
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if(l & 1) eval(l), tmpL = Monoid::op(tmpL, data[l]), l++;
      if(r & 1) --r, eval(r), tmpR = Monoid::op(data[r], tmpR);
    }
    return Monoid::op(tmpL, tmpR);
  }
  int size() { return n; }
  inline void dum(int r = -1) {
#ifdef DEBUG
    if(r < 0) r = n;
    DEBUG_OUT << "{";
    for(int i = 0; i < min(r, (int) n); i++) DEBUG_OUT << (i ? ", " : "") << get(i);
    DEBUG_OUT << "}" << endl;
#endif
  }
};

/// }}}--- ///

/// --- Monoid examples {{{ ///
constexpr long long inf_monoid = 1e18 + 100;
#include <algorithm>
struct Nothing {
  using T = char;
  using Monoid = Nothing;
  using M = T;
  static constexpr T op(const T &, const T &) { return T(); }
  static constexpr T identity() { return T(); }
  template < class X >
    static constexpr X actInto(const M &, long long, const X &x) {
      return x;
    }
};

template < class U = long long >
struct RangeMin {
  using T = U;
  static T op(const T &a, const T &b) { return std::min< T >(a, b); }
  static constexpr T identity() { return T(inf_monoid); }
};

template < class U = long long >
struct RangeMax {
  using T = U;
  static T op(const T &a, const T &b) { return std::max< T >(a, b); }
  static constexpr T identity() { return T(-inf_monoid); }
};

template < class U = long long >
struct RangeSum {
  using T = U;
  static T op(const T &a, const T &b) { return a + b; }
  static constexpr T identity() { return T(0); }
};

template < class U >
struct RangeProd {
  using T = U;
  static T op(const T &a, const T &b) { return a * b; }
  static constexpr T identity() { return T(1); }
};

template < class U = long long >
struct RangeOr {
  using T = U;
  static T op(const T &a, const T &b) { return a | b; }
  static constexpr T identity() { return T(0); }
};

#include <bitset>

template < class U = long long >
struct RangeAnd {
  using T = U;
  static T op(const T &a, const T &b) { return a & b; }
  static constexpr T identity() { return T(-1); }
};

template < size_t N >
struct RangeAnd< std::bitset< N > > {
  using T = std::bitset< N >;
  static T op(const T &a, const T &b) { return a & b; }
  static constexpr T identity() { return std::bitset< N >().set(); }
};

/// }}}--- ///

/// --- M_act examples {{{ ///
template < class U = long long, class V = U >
struct RangeMinAdd {
  using X = U;
  using M = V;
  using Monoid = RangeMin< U >;
  static M op(const M &a, const M &b) { return a + b; }
  static constexpr M identity() { return 0; }
  static X actInto(const M &m, long long, const X &x) { return m + x; }
};

template < class U = long long, class V = U >
struct RangeMaxAdd {
  using X = U;
  using M = V;
  using Monoid = RangeMax< U >;
  static M op(const M &a, const M &b) { return a + b; }
  static constexpr M identity() { return 0; }
  static X actInto(const M &m, long long, const X &x) { return m + x; }
};

template < class U = long long, class V = U >
struct RangeMinSet {
  using M = U;
  using Monoid = RangeMin< U >;
  using X = typename Monoid::T;
  static M op(const M &a, const M &) { return a; }
  static constexpr M identity() { return M(-inf_monoid); }
  static X actInto(const M &m, long long, const X &x) { return m == identity() ? x : m; }
};

template < class U = long long, class V = U >
struct RangeMaxSet {
  using M = U;
  using Monoid = RangeMax< U >;
  using X = typename Monoid::T;
  static M op(const M &a, const M &) { return a; }
  static constexpr M identity() { return M(-inf_monoid); }
  static X actInto(const M &m, long long, const X &x) { return m == identity() ? x : m; }
};

template < class U = long long, class V = U >
struct RangeSumAdd {
  using X = U;
  using M = V;
  using Monoid = RangeSum< U >;
  static M op(const M &a, const M &b) { return a + b; }
  static constexpr M identity() { return 0; }
  static X actInto(const M &m, long long n, const X &x) { return m * n + x; }
};

template < class U = long long, class V = U >
struct RangeSumSet {
  using X = U;
  using M = V;
  using Monoid = RangeSum< U >;
  static M op(const M &a, const M &) { return a; }
  static constexpr M identity() { return M(-inf_monoid); }
  static X actInto(const M &m, long long n, const X &x) {
    return m == identity() ? x : m * n;
  }
};

template < class U, class V = U >
struct RangeProdMul {
  using X = U;
  using M = V;
  using Monoid = RangeProd< U >;
  static M mpow(M a, long long b) {
    X r(1);
    while(b) {
      if(b & 1) r = r * a;
      a = a * a;
      b >>= 1;
    }
    return r;
  }
  static M op(const M &a, const M &b) { return a * b; }
  static constexpr M identity() { return M(1); }
  static X actInto(const M &m, long long n, const X &x) { return x * mpow(m, n); }
};

template < class U, class V = U >
struct RangeProdSet {
  using X = U;
  using M = V;
  using Monoid = RangeProd< U >;
  static M op(const M &a, const M &) { return a; }
  static constexpr M identity() { return V::unused; }
  static X actInto(const M &m, long long n, const X &) {
    if(m == identity()) return;
    return RangeProdMul< U, V >::mpow(m, n);
  }
};

template < class U = long long, class V = U >
struct RangeOr2 {
  using X = U;
  using M = V;
  using Monoid = RangeOr< U >;
  static M op(const M &a, const M &b) { return a | b; }
  static constexpr M identity() { return M(0); }
  static X actInto(const M &m, long long, const X &x) { return m | x; }
};

template < class U = long long, class V = U >
struct RangeAnd2 {
  using X = U;
  using M = V;
  using Monoid = RangeAnd< U >;
  static M op(const M &a, const M &b) { return a & b; }
  static constexpr M identity() { return M(-1); }
  static X actInto(const M &m, long long, const X &x) { return m & x; }
};

template < class U, size_t N >
struct RangeAnd2< U, std::bitset< N > > {
  using X = U;
  using M = std::bitset< N >;
  using Monoid = RangeAnd< U >;
  static M op(const M &a, const M &b) { return a & b; }
  static constexpr M identity() { return std::bitset< N >().set(); }
  static X actInto(const M &m, long long, const X &x) { return m & x; }
};
/// }}}--- ///

using Seg = LazySegmentTree< RangeSumAdd<modint> >;


// NOTE : use H with larger N
/// --- Modulo Factorial {{{ ///
#include <cassert>
#include <cstddef>
template < std::size_t N, int mod = static_cast< int >(1e9 + 7) >
struct Factorial {
  using integer = long long;
  constexpr integer extgcd(integer a, integer b, integer &x, integer &y) {
    integer d = 0;
    return b == 0 ? (x = a < 0 ? -1 : 1, y = 0, a < 0 ? -a : a)
      : (d = extgcd(b, a % b, y, x), y -= a / b * x, d);
  }
  constexpr integer modinv(integer a) {
    integer x = 0, y = 0;
    extgcd(a, mod, x, y);
    if(x < 0)
      x += mod;
    else if(x == mod)
      x = 0;
    return x;
  }
  int arr[N + 1], inv[N + 1];
  integer operator[](int i) const { return arr[i]; }
  Factorial() : arr(), inv() {
    arr[0] = 1;
    for(std::size_t i = 1; i <= N; i++) {
      arr[i] = (integer) i * arr[i - 1] % mod;
    }
    inv[N] = modinv(arr[N]);
    for(int i = N - 1; i >= 0; i--) {
      inv[i] = (integer)(i + 1) * inv[i + 1] % mod;
    }
  }
  integer C(int n, int r) const {
    if(n < 0 || r < 0 || n < r) return 0;
    assert(n <= N);
    return (integer) arr[n] * inv[r] % mod * inv[n - r] % mod;
  }
  integer H(int n, int r) const { return C(n + r - 1, r); }
};
/// }}}--- ///

constexpr int mod = 1e9 + 7;
const int N = 2e5 + 10;
Factorial< N * 2, mod > fact;



int n, m;
int r, b;
int rmax;
string s;

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  cin >> n >> m;
  cin >> s;
  if(s[0] == 'B') for(auto &e : s) e = e == 'R' ? 'B' : 'R';
  bool allR = 1;
  for(auto e : s) allR &= e == 'R';

  if(allR) {
    dump("allR");
    modint ans;
    for(int B = 0; B <= n; B++) {
      int R = n - B - B;
      ans += modint(fact.C(R + B, R));
      ans += modint(fact.C(R + B - 1, R));
    }
    cout << ans << endl;
    return 0;
  }

  if(n % 2 == 1) {
    cout << 0 << endl;
    dump("odd");
    return 0;
  }

  int c = 0;
  rmax = m;
  bool first = 1;
  for(int i = 0; i <= m; i++) {
    if(s[i] == 'B') {
      if(c) {
        if(c % 2 == 0 && first) rmax = min(rmax, c + 1);
        if(c % 2 == 1) rmax = min(rmax, c);
      }
      c = 0;
      first = 0;
    } else c++;
  }

  dump(rmax);

  // RB

  // vector<modint> dp(n + 1);
  Seg dp(n + 1);
  dp.set(0, 1);

  modint ans;

  for(int i = 0; i <= n - 1; i+=2) {
    dp.act(i + 2, min<int>(n - 1, i + 1 + rmax) + 1, dp.get(i));
    if(i + 1 + rmax >= n) {
      int f = n - i - 1;
      dump(i, dp.get(i), f);
      ans += dp.get(i) * (f + 1);
    }
  }
  cout << ans << endl;
  dp.dum();

  return 0;
}
