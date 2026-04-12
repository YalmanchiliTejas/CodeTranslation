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

void input() {}
template <class T, class... Ts> void input(T &a, Ts &... as) {
  cin >> a;
  input(as...);
}
template <class V> istream &operator>>(istream &i, vector<V> &a) {
  for (auto &e : a)
    i >> e;
  return i;
}

void print() { cout << endl; }
template <class T> void print(T const &a) { cout << a << endl; }
template <class T, class... Ts> void print(T const &a, Ts const &... as) {
  cout << a << " ";
  print(as...);
}
using OS = ostream;
template <class F, class S> OS &operator<<(OS &o, pair<F, S> const &pair) {
  return o << "(" << pair.first << " : " << pair.second << ")";
}
template <size_t I, size_t N, class... Ts> struct OutputTuple;
template <> struct OutputTuple<1, 0> {
  OS &operator()(OS &o, tuple<> const &t) { return o; }
};
template <size_t N, class... Ts> struct OutputTuple<N, N, Ts...> {
  OS &operator()(OS &o, tuple<Ts...> const &t) { return o << get<N - 1>(t); }
};
template <size_t I, size_t N, class... Ts> struct OutputTuple {
  OS &operator()(OS &o, tuple<Ts...> const &t) {
    return OutputTuple<I + 1, N, Ts...>{}(o << get<I - 1>(t) << ",", t);
  }
};
template <class... Ts> OS &operator<<(OS &o, tuple<Ts...> const &t) {
  return OutputTuple<1, sizeof...(Ts), Ts...>{}(o << "(", t) << ")";
}
template <class C> ostream &outputContainer(OS &o, C const &a) {
  o << "[";
  for (auto i = a.begin(), e = a.end(); i != e; o << ((++i != e) ? ", " : ""))
    o << *i;
  return o << "]";
}
template <class V> OS &operator<<(OS &o, list<V> const &a) {
  return outputContainer(o, a);
}
template <class V> OS &operator<<(OS &o, vector<V> const &a) {
  return outputContainer(o, a);
}
template <class V> OS &operator<<(OS &o, set<V> const &a) {
  return outputContainer(o, a);
}
template <class V> OS &operator<<(OS &o, unordered_set<V> const &a) {
  return outputContainer(o, a);
}
template <class K, class V> OS &operator<<(OS &o, map<K, V> const &a) {
  return outputContainer(o, a);
}
template <class V> OS &operator<<(OS &o, unordered_multiset<V> const &a) {
  return outputContainer(o, a);
}
template <class K, class V>
OS &operator<<(OS &o, unordered_map<K, V> const &a) {
  return outputContainer(o, a);
}

template <class Tuple, int I = tuple_size<Tuple>::value - 1> struct TupleHash {
  static size_t compute(size_t h, Tuple const &t) {
    auto v = get<I>(t);
    return TupleHash<Tuple, I - 1>::compute(h * 31 + hash<decltype(v)>{}(v), t);
  }
};
template <class Tuple> struct TupleHash<Tuple, -1> {
  static size_t compute(size_t h, Tuple const &tuple) { return h; }
};
namespace std {
template <typename... T> struct hash<tuple<T...>> {
  size_t operator()(tuple<T...> const &t) const {
    return TupleHash<tuple<T...>>::compute(17, t);
  }
};
} // namespace std

using lli = long long int;
lli gcd(lli const p, lli const q) { return q == 0 ? p : gcd(q, p % q); }
lli pow(lli const a, lli const n, lli const m) {
  return (!n) ? 1 : (n & 1) ? (((a % m) * pow(a, n - 1, m)) % m) : [=] {
    lli b = pow(a, n / 2, m);
    return (b * b) % m;
  }();
}
lli inv(lli const a, lli const p) { return pow(a, p - 2, p); }
constexpr lli MOD = 1e9 + 7;

int main() {
  int H, W;
  input(H, W);
  vector<vector<char>> c(H);
  for (size_t i = 0; i < H; i++) {
    vector<char> r(W);
    input(r);
    c[i] = r;
  }
  auto dist = [](int i0, int j0, int i1, int j1) {
    return abs(i0 - i1) + abs(j0 - j1);
  };
  vector<int> l(H, 10000);
  vector<int> r(H, -10000);
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; j++) {
      if (c[i][j] == 'B') {
        l[i] = min(l[i], j);
        r[i] = max(r[i], j);
      }
    }
  }
  vector<int> t(W, 10000);
  vector<int> b(W, -10000);
  for (int j = 0; j < W; ++j) {
    for (int i = 0; i < H; i++) {
      if (c[i][j] == 'B') {
        t[j] = min(t[j], i);
        b[j] = max(b[j], i);
      }
    }
  }
  typedef tuple<int, int> int2;
  unordered_set<int2> B;
  for (size_t i = 0; i < H; i++) {
    B.insert(int2(i, l[i]));
    B.insert(int2(i, r[i]));
  }
  for (size_t j = 0; j < W; j++) {
    B.insert(int2(t[j], j));
    B.insert(int2(b[j], j));
  }
  // print(l, r, t, b);
  // print(B);
  int max_dist = 0;
  vector<int2> B_vec(B.begin(), B.end());
  for (size_t i = 0; i < B_vec.size(); i++) {
    for (size_t j = 0; j < B_vec.size(); j++) {
      int x = get<0>(B_vec[i]);
      int y = get<1>(B_vec[i]);
      int z = get<0>(B_vec[j]);
      int w = get<1>(B_vec[j]);
      if (0 <= x && x < H && 0 <= z && z < H && 0 <= y && y < W && 0 <= w &&
          w < W) {
        max_dist = max(max_dist, dist(x, y, z, w));
      }
    }
  }

  print(max_dist);
}

