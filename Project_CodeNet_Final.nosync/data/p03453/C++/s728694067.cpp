#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <locale>
#include <iostream>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template <typename T> int len(const T &x) { return x.size(); }

template<typename T>
vector<T> table(int n, T v) { return vector<T>(n, v); }

template <class... Args>
auto table(int n, Args... args) {
  auto val = table(args...);
  return vector<decltype(val)>(n, move(val));
}

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

template<int M, bool IsPrime = false>
class Modulo {
  using ll = long long;
  int n;
  static enable_if_t<IsPrime, ll> inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
  }
public:
  Modulo () : n(0) {;}
  Modulo (int m) : n(m) {
    if (n >= M) n %= M;
    else if (n < 0) n = (n % M + M) % M;
  }
  Modulo (ll m) {
    if (m >= M) m %= M;
    else if (m < 0) m = (m % M + M) % M;
    n = m;
  }
  explicit operator int() const { return n; }
  explicit operator ll() const { return n; }
  bool operator==(const Modulo &a) const { return n == a.n; }
  Modulo &operator+=(const Modulo &a) { n += a.n; if (n >= M) n -= M; return *this; }
  Modulo &operator-=(const Modulo &a) { n -= a.n; if (n < 0) n += M; return *this; }
  Modulo &operator*=(const Modulo &a) { n = (ll(n) * a.n) % M; return *this; }
  Modulo operator+(const Modulo &a) const { Modulo res = *this; return res += a; }
  Modulo operator-(const Modulo &a) const { Modulo res = *this; return res -= a; }
  Modulo operator*(const Modulo &a) const { Modulo res = *this; return res *= a; }
  Modulo operator^(int n) const {
    if (n == 0) return Modulo(1);
    const Modulo a = *this;
    Modulo res = (a * a) ^ (n / 2);
    return n % 2 ? res * a : res;
  }
  enable_if_t<IsPrime, Modulo> operator/(const Modulo &a) const {
    return *this * inv(ll(a), M);
  }
  enable_if_t<IsPrime, Modulo> operator/=(const Modulo &a) {
    return *this *= inv(ll(a), M);
  }
};

template<int M, bool IsPrime = false>
bool is_zero(Modulo<M, IsPrime> x) { return int(x) == 0; }
template<int M, bool IsPrime = false>
int abs(Modulo<M, IsPrime> x) { return int(x); }

const int mod = 1000000007;

template<int M = mod> Modulo<M, true> fact(int n, bool sw = true) {
  static vector<Modulo<M, true>> v1 = {1}, v2 = {1};
  if (n >= (int)v1.size()) {
    const int from = v1.size(), to = n + 1024;
    v1.reserve(to);
    v2.reserve(to);
    for (int i = from; i < to; ++i) {
      v1.push_back(v1.back() * Modulo<M, true>(i));
      v2.push_back(v2.back() / Modulo<M, true>(i));
    }
  }
  return sw ? v1[n] : v2[n];
}

template<int M = mod> Modulo<M, true> comb(int a, int b) {
  if (b < 0 || b > a) return 0;
  return fact<M>(a, true) * fact<M>(b, false) * fact<M>(a-b, false);
}

using Mod = Modulo<mod, true>;

template <typename Edge>
pair<vector<typename Edge::Cost>, vector<Mod>>
dijkstra(const vector<vector<Edge>> &g, int s, typename Edge::Cost zero = 0) {
  using Cost = typename Edge::Cost;
  vector<Cost> d(g.size(), ll(1e18));
  vector<Mod> cnt(g.size(), Mod(0));
  d[s] = zero; cnt[s] = 1;
  using P = pair<Cost,int>;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(zero, s));
  while (!que.empty()) {
    Cost dist = que.top().first;
    int v = que.top().second;
    que.pop();
    if (d[v] < dist) continue;
    for (const auto &e: g[v]) {
      if (d[e.to] < d[v] + e.cost) continue;
      if (d[e.to] == d[v] + e.cost) { cnt[e.to] += cnt[v]; continue; }
      d[e.to] = d[v] + e.cost;
      que.push(P(d[e.to], e.to));
      cnt[e.to] = cnt[v];
    }
  }
  return make_pair(d, cnt);
}

struct Edge {
  using Cost = ll;
  int to;
  Cost cost;
  Edge(int t, Cost c) : to(t), cost(c) {}
};

using Graph = vector<vector<Edge>>;

void add_edge(Graph &g, int from, int to, Edge::Cost cost) {
  g[from].emplace_back(to, cost);
  g[to].emplace_back(from, cost);
}

void solve(ll N, ll M, ll S, ll T, vector<ll> U, vector<ll> V, vector<ll> D) {
  Graph g(N);
  REP(i,M) add_edge(g, U[i] - 1, V[i] - 1, D[i]);
  auto dir_s = dijkstra(g, S - 1);
  auto dir_t = dijkstra(g, T - 1);
  ll dist = dir_s.first[T - 1];
  vector<ll> d = dir_s.first;
  // cout << dist << endl;
  vector<int> ok(N, 0);
  REP(i,N) ok[i] = (dir_s.first[i] + dir_t.first[i] == dist);
  vector<Mod> vec;
  REP(i,N) {
    if (!ok[i]) continue;
    if (d[i] * 2 == dist) {
      vec.push_back(dir_s.second[i] * dir_t.second[i]);
    }
    else if (d[i] * 2 < dist) {
      for (auto e: g[i]) {
        int v = e.to;
        if (dir_s.first[i] + dir_t.first[v] + e.cost != dist) continue;
        if (dist < d[v] * 2) {
          vec.push_back(dir_s.second[i] * dir_t.second[v]);
        }
      }
    }
  }
  Mod res = 0, sum = 0;
  for (auto i: vec) {
    // cout << int(i) << endl;
    res -= i * i;
    sum += i;
  }
  res += sum * sum;
  cout << int(res) << endl;
}

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll T;
	ll S;
	ll M;
	ll N;
	scanf("%lld", &N);
	scanf("%lld", &M);
	vector<ll> V(M-1+1);
	vector<ll> D(M-1+1);
	vector<ll> U(M-1+1);
	scanf("%lld", &S);
	scanf("%lld", &T);
	for (int i = 0 ; i <= M-1 ; i++) {
	  scanf("%lld", &U[i]);
	  scanf("%lld", &V[i]);
	  scanf("%lld", &D[i]);
	}
	solve(N, M, S, T, U, V, D);
	return 0;
}
