#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

namespace io {
// Input
void in() {}
template <class T, class... Ts> void in(T &a, Ts &... as) {
  cin >> a;
  in(as...);
}
template <class V> istream &operator>>(istream &i, vector<V> &a) {
  for (auto &e : a)
    i >> e;
  return i;
}
template <class F, class S>
istream &operator>>(istream &i, pair<F, S> const &p) {
  return i >> p.first >> p.second;
}
template <class... Ts> istream &tuple_in(istream &i, Ts &... ts);
istream &tuple_in(istream &i) { return i; }
template <class T, class... Ts>
istream &tuple_in(istream &i, T &t, Ts &... ts) {
  return tuple_in(i >> t, ts...);
}
template <class... Ts, size_t... I>
istream &input_tuple(istream &i, tuple<Ts...> &t, index_sequence<I...>) {
  return tuple_in(i, get<I>(t)...);
}
template <class... Ts> istream &operator>>(istream &i, tuple<Ts...> &t) {
  return input_tuple(i, t,
                     make_index_sequence<tuple_size<tuple<Ts...>>::value>());
}

// Output
void out() { cout << endl; }
template <class T> void out(T const &a) { cout << a << endl; }
template <class T, class... Ts> void out(T const &a, Ts const &... as) {
  cout << a << " ";
  out(as...);
}
template <class F, class S>
ostream &operator<<(ostream &o, pair<F, S> const &p) {
  return o << "(" << p.first << " : " << p.second << ")";
}

template <class... Ts> ostream &tuple_out(ostream &o, Ts const &... ts);
ostream &tuple_out(ostream &o) { return o; }
template <class T> ostream &tuple_out(ostream &o, T const &t) { return o << t; }
template <class T0, class T1, class... Ts>
ostream &tuple_out(ostream &o, T0 const &t0, T1 const &t1, Ts const &... ts) {
  return tuple_out(o << t0 << ",", t1, ts...);
}
template <class... Ts, size_t... I>
ostream &output_tuple(ostream &o, tuple<Ts...> const &t, index_sequence<I...>) {
  return tuple_out(o, get<I>(t)...);
}
template <class... Ts> ostream &operator<<(ostream &o, tuple<Ts...> const &t) {
  return output_tuple(o << "(", t,
                      make_index_sequence<tuple_size<tuple<Ts...>>::value>())
         << ")";
}

template <class C,
          typename enable_if<!is_pointer<C>::value && !is_array<C>::value &&
                                 !is_same<C, char>::value &&
                                 !is_same<C, string>::value,
                             nullptr_t>::type = nullptr>
ostream &operator<<(ostream &o, C const &a) {
  return a.empty() ? (o << "[]") : ([&o, &a]() -> ostream & {
    o << "[" << *a.begin();
    accumulate(next(a.begin()), a.end(), 0,
               [&o](auto &x, auto e) { return (o << "," << e), x; });
    return o << "]";
  }());
}
} // namespace io

template <class... Xs> void input(Xs &... xs) { io::in(xs...); }
template <class... Xs> void print(Xs const &... xs) { io::out(xs...); }

// Hash
namespace hashcode {
template <class... Ts> size_t hash_args(size_t h, Ts const &... ts);
size_t hash_args(size_t h) { return h; }
template <class T> size_t hash_args(size_t h, T const &t) {
  return h * 31 + hash<T>{}(t);
}
template <class T0, class T1, class... Ts>
size_t hash_args(size_t h, T0 const &t0, T1 const &t1, Ts const &... ts) {
  return hash_args(h * 31 + hash<T0>{}(t0), t1, ts...);
}
template <class... Ts, size_t... I>
size_t hash_tuple(tuple<Ts...> const &t, index_sequence<I...>) {
  return hash_args(17, get<I>(t)...);
}
} // namespace hashcode
namespace std {
template <class... Ts> struct hash<tuple<Ts...>> {
  size_t operator()(tuple<Ts...> const &t) const {
    return hashcode::hash_tuple(t, index_sequence_for<Ts...>());
  }
};
template <class T> struct hash<unordered_set<T>> {
  size_t operator()(unordered_set<T> const &s) const {
    return accumulate(s.begin(), s.end(), 0, [](auto const &a, auto const &e) {
      return a + hash<T>{}(e);
    });
  }
};
} // namespace std

// Range
using namespace std;

using lli = long long int;
template <class T = lli> vector<T> range(T const &begin, T const &end) {
  vector<T> ret(end - begin);
  iota(ret.begin(), ret.end(), begin);
  return ret;
}
template <class T = lli> vector<T> range(T const &end) {
  return range(T(), end);
}
template <class T = lli> vector<T> vec(size_t n, T &&init = T()) {
  return vector<T>(n, init);
}
template <class Itr, class T = typename iterator_traits<Itr>::value_type>
vector<T> vec(Itr begin, Itr end) {
  return vector<T>(begin, end);
}

// MOD
constexpr lli gcd(lli const p, lli const q) {
  return q == 0 ? p : gcd(q, p % q);
}
constexpr lli pow(lli const a, lli const n, lli const m) {
  return (!n) ? 1 : (n & 1) ? (((a % m) * pow(a, n - 1, m)) % m) : [=] {
    lli b = pow(a, n / 2, m);
    return (b * b) % m;
  }();
}
constexpr lli inv(lli const a, lli const p) { return pow(a, p - 2, p); }
constexpr lli MOD = 1e9 + 7;

// Main
int main() {
  lli N;
  input(N);
  auto A = vec(N);
  input(A);
  multiset<lli, greater<lli>> B{};
  for (auto const &ai : A) {
    auto pos = B.upper_bound(ai);
    if (pos != B.end())
      B.erase(pos);
    B.insert(ai);
    // print(ai, B);
  }
  print(B.size());
}
