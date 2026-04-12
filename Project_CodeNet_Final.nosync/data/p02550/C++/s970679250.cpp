#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#ifdef JUMPAKU_LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// Utility
using std::get;
using std::make_pair;
using std::make_tuple;
using std::make_unique;
using std::stold;
using std::stoll;
using std::operator""s;
using std::abs;

// Types
using std::bitset;
using std::deque;
using std::list;
using std::multiset;
using std::pair;
using std::tuple;
template <class T> using opt = std::optional<T>;
using ll = /** __int128; //*/ long long int;
using lf = long double;
using str = std::string;
template <class V, class H = std::hash<V>>
using u_multiset = std::unordered_multiset<V, H>;
template <class V, class H = std::hash<V>>
using u_set = std::unordered_set<V, H>;
template <class K, class V, class H = std::hash<K>>
using u_multimap = std::unordered_multimap<K, V, H>;
template <class K, class V, class H = std::hash<K>>
using u_map = std::unordered_map<K, V, H>;
template <class T> using vec = std::vector<T>;
template <class V, class C = std::less<V>>
using priority_queue = std::priority_queue<V, vec<V>, C>;
using vecl = vec<ll>;
using vecf = vec<lf>;
using vecs = vec<str>;
template <class V> using u_graph = u_map<V, u_set<V>>;
using v_graph = vec<vec<int>>;
template <typename _Signature> using fun = std::function<_Signature>;

// Algorithms
using std::accumulate;
using std::all_of;
using std::any_of;
using std::back_inserter;
using std::copy;
using std::copy_if;
using std::count;
using std::count_if;
using std::find_if;
using std::for_each;
using std::inserter;
using std::lower_bound;
using std::max;
using std::max_element;
using std::min;
using std::min_element;
using std::next_permutation;
using std::none_of;
using std::partial_sum;
using std::remove_if;
using std::replace_if;
using std::reverse;
using std::set_difference;
using std::set_intersection;
using std::set_symmetric_difference;
using std::set_union;
using std::sort;
using std::swap;
using std::transform;
using std::unique;
using std::upper_bound;

namespace utils {
str to_string(__int128 const &x) { return std::to_string((long long)x); }
template <class T> T clamp(T const &v, T const &l, T const &h) {
  return min(h, max(l, v));
}
ll gcd(ll p, ll q) { return (q == 0) ? p : gcd(q, p % q); }
ll lcm(ll p, ll q) { return p / gcd(q, p) * q; }
ll sign(ll x) { return ll{x < 0 ? -1 : x > 0 ? 1 : 0}; }
bool odd(ll n) { return n & 1; }
bool even(ll n) { return !odd(n); }
bool imply(bool p, bool q) { return !p || q; }
bool iff(bool p, bool q) { return p == q; }
} // namespace utils
using std::to_string;
using utils::clamp;
using utils::even;
using utils::gcd;
using utils::iff;
using utils::imply;
using utils::lcm;
using utils::odd;
using utils::sign;
using utils::to_string;

namespace io {
// Input
using IS = std::istream;
IS &in(IS &);
IS &in(IS &i) { return i; }
template <class T, class... Ts> IS &in(IS &i, T &a, Ts &... as) {
  return in(i >> a, as...);
}
IS &operator>>(IS &i, __int128 &x) {
  long long int xx;
  i >> xx;
  x = xx;
  return i;
}
template <class V> IS &operator>>(IS &i, vec<V> &a) {
  for (auto &ai : a)
    i >> ai;
  return i;
}
template <class F, class S> IS &operator>>(IS &i, pair<F, S> &p) {
  return i >> p.first >> p.second;
}
template <class... Ts> IS &operator>>(IS &i, tuple<Ts...> &t) {
  return apply([&](auto &... ts) -> IS & { return in(i, ts...); }, t);
}
// Output
using OS = std::ostream;
OS &out_join(OS &o, str const &) { return o; }
template <class T> OS &out_join(OS &o, str const &, T const &a) {
  return o << a;
}
template <class T, class... Ts>
OS &out_join(OS &o, str const &sep, T const &a, Ts const &... as) {
  return out_join(o << a << sep, sep, as...);
}
OS &operator<<(OS &o, __int128 const &x) { return o << (long long int)x; }
template <class F, class S> OS &operator<<(OS &o, pair<F, S> const &p) {
  return o << p.first << ":" << p.second;
}
template <class... Ts, size_t... I>
OS &tuple_out(OS &o, tuple<Ts...> const &t, std::index_sequence<I...>) {
  return out_join(o, ",", get<I>(t)...);
}
template <class... Ts> OS &operator<<(OS &o, tuple<Ts...> const &t) {
  return tuple_out(o << "(", t, std::make_index_sequence<sizeof...(Ts)>())
         << ")";
}
template <class T> struct Joiner {
  str const pre;
  str const post;
  str const sep;
  vec<T> const container;
  template <class Itr>
  Joiner(Itr const &begin, Itr const &end, str const &sep, str const &pre,
         str const &post)
      : pre(pre), post(post), sep(sep), container(begin, end) {}
};
template <class T> OS &operator<<(OS &o, Joiner<T> const &joiner) {
  auto itr = joiner.container.begin();
  auto end = joiner.container.end();
  o << joiner.pre;
  if (itr != end)
    o << *(itr++);
  while (itr != end)
    o << joiner.sep << *(itr++);
  return o << joiner.post;
}
template <class Itr>
auto join(Itr const &b, Itr const &e, str const &sep = ""s,
          str const &pre = ""s, str const &post = ""s) {
  using T = typename std::iterator_traits<Itr>::value_type;
  return Joiner<T>(b, e, sep, pre, post);
}
template <class T> io::OS &operator<<(io::OS &o, opt<T> const &opt) {
  return opt.has_value() ? (o << "Some(" << opt.value() << ")") : (o << "None");
}
template <class C, std::enable_if_t<
                       !std::is_same_v<C, str> && !std::is_array_v<C> &&
                           !std::is_pointer_v<C> && !std::is_arithmetic_v<C>,
                       std::nullptr_t> = nullptr>
OS &operator<<(OS &o, C const &a) {
  return o << join(a.begin(), a.end(), ",", "[", "]");
}
} // namespace io
using std::cin;
using std::cout;
auto init_io = []() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << std::fixed << std::setprecision(15);
};
auto input = [](auto &... a) { io::in(cin, a...); };
auto print = [](auto const &... a) { io::out_join(cout, " ", a...) << "\n"; };
#ifdef JUMPAKU_DEBUG
auto dump = [](auto const &... a) {
  io::out_join(std::cerr, " "s, a...) << "\n";
};
#else
auto dump = [](auto const &...) {};
#endif
using io::join;

// Hash
namespace hashcode {
template <class... Ts> size_t hash_args(size_t h, Ts const &... ts);
size_t hash_args(size_t h) { return h; }
template <class T, class... Ts>
size_t hash_args(size_t h, T const &t, Ts const &... ts) {
  constexpr std::hash<T> hasher;
  return hash_args(((h << 10) - h) ^ hasher(t), ts...);
}
template <class... Ts, size_t... I>
size_t hash_tuple(tuple<Ts...> const &t, std::index_sequence<I...>) {
  return hash_args(17, get<I>(t)...);
}
} // namespace hashcode
namespace std {
#if __GNUC__ != 9 || defined(__STRICT_ANSI__)
template <> struct hash<__int128> {
  size_t operator()(__int128 const &t) const {
    return (t & 0xffffff) ^ ((t >> 63) & 0xffffff);
  }
};
#endif
template <class... Ts> struct hash<tuple<Ts...>> {
  size_t operator()(tuple<Ts...> const &t) const {
    size_t h = hashcode::hash_tuple(t, std::index_sequence_for<Ts...>());
    return h ^ (h >> 32);
  }
};
template <class T> struct hash<u_set<T>> {
  size_t operator()(u_set<T> const &t) const {
    constexpr std::hash<T> hasher;
    return accumulate(
        t.begin(), t.end(), (size_t)0,
        [&](auto acc, auto const &ti) { return acc + hasher(ti); });
  }
};
} // namespace std

// Range
namespace ranges {
template <class T, class Itr> struct iterator_base {
  using difference_type = ll;
  using value_type = T;
  using pointer = T *;
  using reference = T &;
  using iterator_category = std::random_access_iterator_tag;
  ll i;
  iterator_base(ll const &i) : i(i) {}
  bool operator==(Itr const &itr) const { return i == itr.i; }
  bool operator!=(Itr const &itr) const { return i != itr.i; }
  ll operator-(Itr const &itr) const { return i - itr.i; }
  Itr operator++(int) { return with(i++); }
  Itr operator--(int) { return with(i--); }
  Itr operator+(ll const &n) const { return with(i + n); }
  Itr operator-(ll const &n) const { return with(i - n); }
  Itr &operator+=(ll const &n) {
    i += n;
    return self();
  }
  Itr &operator-=(ll const &n) { return self() += (-n); }
  Itr &operator++() { return self() += 1; }
  Itr &operator--() { return self() -= 1; }

protected:
  virtual Itr with(ll i) const = 0;
  virtual Itr &self() = 0;
};
template <class T> struct seq_base {
  ll const b;
  ll const e;
  seq_base(ll b, ll e) : b(b), e(max(b, e)) {}
  ll size() const { return e - b; }
  bool empty() const { return size() == 0; }
};
template <class T> struct seq : seq_base<T> {
  struct iterator : iterator_base<T, iterator> {
    seq<T> const &s;
    iterator(seq<T> const &s, ll const &i)
        : iterator_base<T, iterator>(i), s(s) {}
    iterator(iterator const &) = default;
    iterator with(ll i) const override { return iterator(s, i); }
    iterator &self() override { return *this; }
    T operator*() const { return s[this->i]; }
    iterator &operator=(iterator const &itr) {
      this->i = itr.i;
      return *this;
    }
  };
  fun<T(ll)> const f;
  seq(ll b, ll e, fun<T(ll)> const &f) : seq_base<T>(b, e), f(f) {}
  iterator begin() const { return iterator(*this, 0); }
  iterator end() const { return iterator(*this, this->size()); }
  T operator[](ll i) const { return f(i + this->b); }
};

struct range : seq_base<ll> {
  struct iterator : iterator_base<ll, iterator> {
    iterator(ll const &i) : iterator_base<ll, iterator>(i) {}
    iterator with(ll i) const override { return iterator(i); }
    iterator &self() override { return *this; }
    ll operator*() const { return i; }
  };
  range(ll n) : range(0, n) {}
  range(ll b, ll e) : seq_base<ll>(b, e) {}
  iterator begin() const { return iterator(b); }
  iterator end() const { return iterator(e); }
  bool has(ll x) const { return b <= x && x < e; }
  ll operator[](ll i) const { return i + b; }
};
} // namespace ranges
using range = ranges::range;
range::iterator end(ll i) { return range::iterator(i); }
range::iterator begin(ll i = 0) { return range::iterator(i); }
template <class F> auto seq(ll n, F const &f) {
  using T = decltype(f(std::declval<ll>()));
  return ranges::seq<T>(0LL, n, f);
}

#include <chrono>
class stopwatch {
#ifdef JUMPAKU_DEBUG
  using Clock = std::chrono::high_resolution_clock;
  using Duration = Clock::duration;
  using TimePoint = Clock::time_point;
  bool isRunning;
  Duration total_duration;
  TimePoint last_lap;
  double castToSeconds(Duration const &d) const {
    return 1e-9 *
           std::chrono::duration_cast<std::chrono::nanoseconds>(d).count();
  }

public:
  stopwatch() : isRunning(false), total_duration(std::chrono::nanoseconds{0}){};
  void reset() {
    isRunning = false;
    total_duration = std::chrono::nanoseconds{0};
    std::cerr << "=DEBUG= Stopwatch::reset()\n";
  }
  void start() {
    auto current = Clock::now();
    if (isRunning)
      return;
    isRunning = true;
    last_lap = current;
    std::cerr << "=DEBUG= Stopwatch::start()\n";
  }
  void restart() {
    last_lap = Clock::now();
    total_duration = std::chrono::nanoseconds{0};
    isRunning = true;
    std::cerr << "=DEBUG= Stopwatch::restart()\n";
  }
  void stop() {
    auto current = Clock::now();
    if (!isRunning)
      return;
    isRunning = false;
    total_duration += current - last_lap;
    std::cerr << "=DEBUG= Stopwatch::stop()\n";
  }
  double lap() {
    auto current = Clock::now();
    if (isRunning) {
      total_duration += current - last_lap;
      last_lap = current;
    }
    auto seconds = castToSeconds(total_duration);
    std::cerr << "=DEBUG= Stopwatch::lap()  : " << seconds << "[s]\n";
    return seconds;
  }
#else
public:
  void start() {}
  void reset() {}
  void restart() {}
  void stop() {}
  double lap() { return 0.0; }
#endif
};

constexpr lf PI = 3.141592653589793238462643383279502884L;
constexpr ll MOD = 998244353;

#endif /* TEMPLATE_HPP */

/**
// DP Definition
using Data = struct {};
using Key = tuple<>;
using Value = ll;
using Cache = u_map<Key, Value>;
struct DP {
  Data data;
  Cache cache;
  DP(Data const &data) : data(data), cache((ll)1e6) {}
  Value compute(Key const &key) {
    if (IS_INITIAL)
      return INITIAL_VALUE;
    if (auto found = cache.find(key); found != cache.end())
      return found->second;
    return cache[key] = RECURSION_CALL(this->compute(Key{}));
  }
};
// DP Call
/*
  DP dp(Data{});
  print(dp.compute(Key{}));
*/

void solve();
int main(int, char *[]) {
  init_io();
  ll t = 1;
  /** input(t); /**/
  while (t--)
    solve();
  cout.flush();
}
/**
 * MOD
 */
#ifndef JUMPAKU_MOD_HPP
#define JUMPAKU_MOD_HPP

#ifndef TEMPLATE_HPP
#include "../templates/template.hpp"
#endif

namespace mod {
using longlong = long long;

longlong pow(longlong a, longlong n, longlong m) {
  if (n == 0)
    return 1;
  if (n & 1)
    return ((a % m) * pow(a, n - 1, m)) % m;
  auto b = pow(a, n / 2, m);
  return (b * b) % m;
}
longlong inv(longlong a, longlong p) { return pow(a, p - 2, p); }

struct ModCache {
  ModCache(int N, longlong mod) : M(mod), fact(N + 1), finv(N + 1) {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i)
      fact[i] = (fact[i - 1] * i) % M;
    finv[N] = inv(fact[N], M);
    for (int i = N; i > 0; --i)
      finv[i - 1] = (finv[i] * i) % M;
  }
  longlong const M;
  vec<longlong> fact;
  vec<longlong> finv;
  longlong comb(longlong n, longlong m) const {
    if (m < 0 || n < m)
      return 0;
    return (fact[n] * ((finv[m] * finv[n - m]) % M)) % M;
  }
  longlong perm(longlong n, longlong m) const {
    if (m < 0 || n < m)
      return 0;
    return (fact[n] * finv[n - m]) % M;
  }
};

// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
  x %= m;
  if (x < 0)
    x += m;
  return x;
}
// @param n `0 <= n`
// @param m `1 <= m`
// @return `(x ** n) % m`
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
  if (m == 1)
    return 0;
  unsigned int _m = (unsigned int)(m);
  unsigned long long r = 1;
  unsigned long long y = safe_mod(x, m);
  while (n) {
    if (n & 1)
      r = (r * y) % _m;
    y = (y * y) % _m;
    n >>= 1;
  }
  return r;
}
// Reference:
// M. Forisek and J. Jancina,
// Fast Primality Testing for Integers That Fit into a Machine Word
// @param n `0 <= n`
constexpr bool is_prime_constexpr(int const &n) {
  if (n <= 1)
    return false;
  if (n == 2 || n == 7 || n == 61)
    return true;
  if (n % 2 == 0)
    return false;
  long long d = n - 1;
  while (d % 2 == 0)
    d /= 2;
  for (long long a : {2, 7, 61}) {
    long long t = d;
    long long y = pow_mod_constexpr(a, t, n);
    while (t != n - 1 && y != 1 && y != n - 1) {
      y = y * y % n;
      t <<= 1;
    }
    if (y != n - 1 && t % 2 == 0) {
      return false;
    }
  }
  return true;
}
template <int n> constexpr bool is_prime_v = is_prime_constexpr(n);

struct mod_helper {
  template <class T> static T &pre_inc(T &x) {
    ++x.m_v;
    if (x.m_v == x.umod())
      x.m_v = 0;
    return x;
  }
  template <class T> static T &pre_dec(T &x) {
    if (x.m_v == 0)
      x.m_v = x.umod();
    x.m_v--;
    return x;
  }
  template <class T> static T post_inc(T &x) {
    T result = x;
    pre_inc(x);
    return result;
  }
  template <class T> static T post_dec(T &x) {
    T result = x;
    pre_dec(x);
    return result;
  }
  template <class T> static T &plusAsign(T &x, int const &v) {
    x.m_v += v;
    if (x.m_v >= x.umod())
      x.m_v -= x.umod();
    return x;
  }
  template <class T> static T &minusAsign(T &x, int const &v) {
    x.m_v += x.umod() - v;
    if (x.m_v >= x.umod())
      x.m_v -= x.umod();
    return x;
  }
  template <class T> static T unaryMinus(T const &x) {
    T r = x;
    if (r.m_v == 0)
      return r;
    r.m_v = r.umod() - r.m_v;
    return r;
  }
  template <class T> static io::OS &out(io::OS &o, T const &x) {
    return o << x.val() << "(%" << x.mod() << ")";
  }
  template <class T,
            std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
  static constexpr T reduce(T const &v, T const &m) {
    if (0 <= v && v < m)
      return v;
    T u = v % m;
    return (u >= 0) ? u : (m + u);
  }
};
template <class T, class U, class V>
bool constexpr are_operatable_v = std::conditional_t<
    (std::is_same_v<T, V> && std::is_same_v<U, V>) ||
        (std::is_same_v<T, V> && std::is_convertible_v<U, int>) ||
        (std::is_convertible_v<U, int> && std::is_same_v<U, V>),
    std::true_type, std::true_type>::value;

template <int M, std::enable_if_t<(M > 0)> * = nullptr> struct static_modint {
  using This = static_modint;
  static int constexpr mod() { return M; }

  static This &timesAsign(This &x, int const &rhs) {
    unsigned long long int &&prod = static_cast<unsigned long long int>(x.m_v) *
                                    static_cast<unsigned long long int>(rhs);
    x.m_v = static_cast<int>(
        mod_helper::reduce(prod, static_cast<unsigned long long int>(x.mod())));
    return x;
  }
  static_modint(int const &v = 0) : m_v(mod_helper::reduce(v, mod())) {}
  static_modint(This const &v) = default;
  static_modint(This &&v) = default;
  This &operator=(This const &v) = default;
  This &operator=(This &&v) = default;
  This &operator=(int const &v) {
    m_v = mod_helper::reduce(v, mod());
    return *this;
  }
  This &operator=(int &&v) {
    m_v = mod_helper::reduce(std::move(v), mod());
    return *this;
  }
  explicit operator int() const { return m_v; }
  friend class mod_helper;
  This &operator++() { return mod_helper::pre_inc(*this); }
  This &operator--() { return mod_helper::pre_dec(*this); }
  This operator++(int) { return mod_helper::post_inc(*this); }
  This operator--(int) { return mod_helper::post_dec(*this); }
  This &operator+=(const This &rhs) {
    return mod_helper::plusAsign(*this, rhs.m_v);
  }
  This &operator-=(const This &rhs) {
    return mod_helper::minusAsign(*this, rhs.m_v);
  }
  This &operator*=(const This &rhs) { return timesAsign(*this, rhs.m_v); }
  This &operator+=(const int &rhs) {
    return mod_helper::plusAsign(*this, mod_helper::reduce(rhs, mod()));
  }
  This &operator-=(const int &rhs) {
    return mod_helper::minusAsign(*this, mod_helper::reduce(rhs, mod()));
  }
  This &operator*=(const int &rhs) {
    return timesAsign(*this, mod_helper::reduce(rhs, mod()));
  }
  This operator+() const { return *this; }
  This operator-() const { return mod_helper::unaryMinus(*this); }
  template <
      class T, class U,
      std::enable_if_t<are_operatable_v<T, U, This>, std::nullptr_t> = nullptr>
  friend This operator+(const T &lhs, const U &rhs) {
    return This(lhs) += rhs;
  }
  template <
      class T, class U,
      std::enable_if_t<are_operatable_v<T, U, This>, std::nullptr_t> = nullptr>
  friend This operator-(const T &lhs, const U &rhs) {
    return This(lhs) -= rhs;
  }
  template <
      class T, class U,
      std::enable_if_t<are_operatable_v<T, U, This>, std::nullptr_t> = nullptr>
  friend This operator*(const T &lhs, const U &rhs) {
    return This(lhs) *= rhs;
  }
  template <
      class T, class U,
      std::enable_if_t<are_operatable_v<T, U, This>, std::nullptr_t> = nullptr>
  friend bool operator==(const T &lhs, const U &rhs) {
    return This(lhs).val() == This(rhs).val();
  }
  template <
      class T, class U,
      std::enable_if_t<are_operatable_v<T, U, This>, std::nullptr_t> = nullptr>
  friend bool operator!=(const T &lhs, const U &rhs) {
    return !(lhs == rhs);
  }
  friend io::OS &operator<<(io::OS &o, const This &x) {
    return mod_helper::out(o, x);
  }
  This pow(ll n) const {
    This y = *this, r = 1;
    while (n) {
      if (n & 1)
        r *= y;
      y *= y;
      n >>= 1;
    }
    return r;
  }
  int val() const { return m_v; }

private:
  static constexpr unsigned int umod() { return (unsigned)M; }
  unsigned int m_v;
};

struct dynamic_modint {
  using This = dynamic_modint;
  static void require_positive_mod(int const &x) {
    if (x <= 0)
      throw std::invalid_argument("mod must be positive");
  }
  static void require_same_mod(This const &x, This const &y) {
    require_same_mod(x.umod(), y.umod());
  }
  static void require_same_mod(int const &xMod, int const &yMod) {
    if (xMod != yMod)
      throw std::logic_error("mod mismatch!");
  }
  static unsigned long long int barrett(int const &m) {
    return ((unsigned long long int)(-1)) / m + 1;
  }
  static This &timesAsign(This &x, int const &rhs) {
    unsigned long long int z = x.m_v;
    z *= x.reduce(rhs);
    x.m_v = x.reduce(z);
    return x;
  }
  dynamic_modint(int const &v, int const &m)
      : m_v(mod_helper::reduce(v, m)), m_m(m), m_im(barrett(m)) {
    require_positive_mod(m_m);
  }
  dynamic_modint(This const &v) = default;
  dynamic_modint(This &&v) = default;
  This &operator=(This const &v) = default;
  This &operator=(This &&v) = default;
  This &operator=(int const &v) {
    m_v = reduce(v);
    return *this;
  }
  This &operator=(int &&v) {
    m_v = reduce(std::move(v));
    return *this;
  }
  explicit operator int() const { return m_v; }
  friend class mod_helper;
  This &operator++() { return mod_helper::pre_inc(*this); }
  This &operator--() { return mod_helper::pre_dec(*this); }
  This operator++(int) { return mod_helper::post_inc(*this); }
  This operator--(int) { return mod_helper::post_dec(*this); }

  This &operator+=(const This &rhs) {
    require_same_mod(*this, rhs);
    return mod_helper::plusAsign(*this, rhs.m_v);
  }
  This &operator+=(const int &rhs) {
    if (rhs < 0)
      return mod_helper::minusAsign(*this, reduce(-rhs));
    return mod_helper::plusAsign(*this, reduce(rhs));
  }
  This &operator-=(const This &rhs) {
    require_same_mod(*this, rhs);
    return mod_helper::minusAsign(*this, rhs.m_v);
  }
  This &operator-=(const int &rhs) {
    if (rhs < 0)
      return mod_helper::plusAsign(*this, reduce(-rhs));
    return mod_helper::minusAsign(*this, reduce(rhs));
  }
  This &operator*=(const This &rhs) {
    require_same_mod(*this, rhs);
    return timesAsign(*this, rhs.m_v);
  }
  This &operator*=(const int &rhs) {
    if (m_v == 0)
      return *this;
    if (rhs < 0) {
      unsigned int x = reduce(-rhs);
      if (x == 0) {
        m_v = 0;
        return *this;
      }
      *this *= x;
      m_v = m_m - m_v;
      return *this;
    }
    return timesAsign(*this, reduce(rhs));
  }
  This const &operator+() const { return *this; }
  This operator-() const { return mod_helper::unaryMinus(*this); }
  template <class U, std::enable_if_t<are_operatable_v<This, U, This>,
                                      std::nullptr_t> = nullptr>
  friend This operator+(const This &lhs, const U &rhs) {
    return This(lhs) += rhs;
  }
  friend This operator+(const int &lhs, const This &rhs) { return rhs + lhs; }
  template <class U, std::enable_if_t<are_operatable_v<This, U, This>,
                                      std::nullptr_t> = nullptr>
  friend This operator-(const This &lhs, const U &rhs) {
    return This(lhs) -= rhs;
  }
  friend This operator-(const int &lhs, const This &rhs) {
    return -(rhs - lhs);
  }
  template <class U, std::enable_if_t<are_operatable_v<This, U, This>,
                                      std::nullptr_t> = nullptr>
  friend This operator*(const This &lhs, const U &rhs) {
    return This(lhs) *= rhs;
  }
  friend This operator*(const int &lhs, const This &rhs) { return rhs * lhs; }
  friend bool operator==(const This &lhs, const This &rhs) {
    require_same_mod(lhs, rhs);
    return lhs.m_v == rhs.m_v;
  }
  friend bool operator==(const This &lhs, const int &rhs) {
    return lhs.m_v == lhs.reduce(rhs);
  }
  friend bool operator==(const int &lhs, const This &rhs) {
    return rhs.reduce(lhs) == rhs.m_v;
  }
  template <
      class T, class U,
      std::enable_if_t<are_operatable_v<T, U, This>, std::nullptr_t> = nullptr>
  friend bool operator!=(const T &lhs, const U &rhs) {
    return !(lhs == rhs);
  }
  friend io::OS &operator<<(io::OS &o, const This &x) {
    return mod_helper::out(o, x);
  }

  This pow(ll n) const {
    This r = *this;
    This y = *this;
    r = 1;
    while (n) {
      if (n & 1)
        r *= y;
      y *= y;
      n >>= 1;
    }
    return r;
  }
  int val() const { return m_v; }
  int mod() const { return m_m; }
  unsigned int umod() const { return m_m; }
  This &with_mod(int const &m) {
    require_positive_mod(m);
    m_m = m;
    m_im = barrett(m);
    return *this;
  }

private:
  unsigned int m_v;
  unsigned int m_m;
  unsigned long long m_im;
  unsigned int reduce(unsigned long long int const &v) const {
    if (v < (unsigned long long int)m_m)
      return v;
    unsigned long long x =
        (unsigned long long)(((unsigned __int128)(v)*m_im) >> 64);
    unsigned int r = (unsigned int)(v - x * m_m);
    if (m_m <= r)
      r += m_m;
    return r;
  }
};

template <int P, std::enable_if_t<is_prime_v<P>, std::nullptr_t> = nullptr>
static_modint<P> inv(static_modint<P> const &a) {
  return a.pow(P - 2);
}
dynamic_modint inv(dynamic_modint const &a) {
  if (!is_prime_constexpr(a.mod()))
    throw std::logic_error("inv with non prime!");
  return a.pow(a.mod() - 2);
}
std::pair<int, int> gcd_inv(int a, int const &mod) {
  a = safe_mod(a, mod);
  if (a == 0)
    return {mod, 0};

  // Contracts:
  // [1] s - m0 * a = 0 (mod b)
  // [2] t - m1 * a = 0 (mod b)
  // [3] s * |m1| + t * |m0| <= b
  long long s = mod, t = a;
  long long m0 = 0, m1 = 1;

  while (t) {
    long long u = s / t;
    s -= t * u;
    m0 -= m1 * u; // |m1 * u| <= |m1| * s <= b

    // [3]:
    // (s - t * u) * |m1| + t * |m0 - m1 * u|
    // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
    // = s * |m1| + t * |m0| <= b

    auto tmp = s;
    s = t;
    t = tmp;
    tmp = m0;
    m0 = m1;
    m1 = tmp;
  }
  // by [3]: |m0| <= b/g
  // by g != b: |m0| < b/g
  if (m0 < 0)
    m0 += mod / s;
  return {s, m0};
}
template <class Modint> std::pair<int, Modint> gcd_inv(Modint const &a) {
  Modint r = a;
  auto &&[gcd, inv] = gcd_inv(a.val(), a.mod());
  r = inv;
  return {gcd, r};
}
} // namespace mod

template <int M> struct std::hash<mod::static_modint<M>> {
  size_t operator()(mod::static_modint<M> const &t) const { return t.val(); }
};
template <> struct std::hash<mod::dynamic_modint> {
  size_t operator()(mod::dynamic_modint const &t) const {
    return ((t.mod() << 10) - t.mod()) | t.val();
  }
};
using mod::dynamic_modint;
using mod::gcd_inv;
using mod::inv;
using mod::ModCache;
using mod::pow;
using mod::static_modint;
#endif
/* end of MOD */
using llm = dynamic_modint;

void solve() {
  ll N, X, M;
  input(N, X, M);
  ll i = 1, j = 2;
  ll ai = (X * X) % M;
  ll aj = (ai * ai) % M;
  while (ai != aj) {
    ai = (ai * ai) % M;
    aj = (aj * aj) % M;
    aj = (aj * aj) % M;
    ++i;
    ++j;
    ++j;
  }
  ll m = j - i;
  ll q = N / m;
  ll r = N % m;
  dump(N, m, q, r);
  if (N <= 2 * m) {
    ll ans = 0;
    ll a;
    for (auto &&i : range(N)) {
      a = i == 0 ? X : ((a * a) % M);
      ans += a;
    }
    print(ans);
    return;
  }

  ll aFront;
  ll ansFront = 0;
  for (auto &&i : range(m)) {
    aFront = i == 0 ? X : ((aFront * aFront) % M);
    ansFront += aFront;
  }

  ll aCycle = aFront;
  ll ansCycle = 0;
  for (auto &&i : range(m)) {
    aCycle = (aCycle * aCycle) % M;
    ansCycle += aCycle;
  }

  ll aRemain = aFront;
  ll ansRemain = 0;
  for (auto &&i : range(r)) {
    aRemain = (aRemain * aRemain) % M;
    ansRemain += aRemain;
  }
  dump(aFront, aCycle, aRemain);
  dump(ansFront, ansCycle, ansRemain);
  print(ansFront + (q - 1) * ansCycle + ansRemain);
}
