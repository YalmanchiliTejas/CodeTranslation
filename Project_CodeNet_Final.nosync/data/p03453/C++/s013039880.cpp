#include <bits/stdc++.h>
using namespace std;

// boost
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;
using vld = vector<ld>;
using vvld = vector<vld>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T& a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T& a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)

const long long INF = 1LL << 60;

// const long long INF = 1LL << 60;

#define USE_MODINT

template <ll ModVal>
struct ModInt {
  ll x;

  ModInt(ll _x = 0) : x((_x % ModVal + ModVal) % ModVal) {
  }

  ModInt operator-() const {
    return ModInt(-x);
  }
  ModInt& operator+=(const ModInt a) {
    x += a.x;
    if (x >= ModVal)
      x -= ModVal;
    return *this;
  }
  ModInt& operator-=(const ModInt a) {
    x = x + ModVal - a.x;
    if (x >= ModVal)
      x -= ModVal;
    return *this;
  }
  ModInt& operator*=(const ModInt a) {
    x *= a.x;
    x %= ModVal;
    return *this;
  }

  // 返り値: gcd(a, b)
  // ax + by = gcd(a, b) を満たす (x, y)
  ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
      x = 1;
      y = 0;
      return a;
    }
    ll tmp = a / b;
    ll d = ext_gcd(b, a - b * tmp, y, x);
    y -= tmp * x;
    return d;
  }

  // 逆元
  ModInt inv() {
    ll u, v;
    ext_gcd(x, ModVal, u, v);
    return ModInt(u);
  }

  ModInt inv(const ModInt a) {
    ll u, v;
    ext_gcd(a.x, ModVal, u, v);
    return ModInt(u);
  }

  ModInt& operator/=(const ModInt a) {
    return (*this) *= inv(a);
  }

  ModInt operator+(const ModInt a) const {
    ModInt retval(*this);
    return retval += a;
  }
  ModInt operator-(const ModInt a) const {
    ModInt retval(*this);
    return retval -= a;
  }
  ModInt operator*(const ModInt a) const {
    ModInt retval(*this);
    return retval *= a;
  }
  ModInt operator/(const ModInt a) const {
    ModInt retval(*this);
    return retval /= a;
  }

  ModInt pow(ll n) {
    ModInt ans(1);
    while (n) {
      if (n & 1)
        ans = ans * x;
      *this = (*this) * (*this);
      n = n >> 1;
    }
    return ans;
  }

  constexpr const ll& value() {
    return this->x;
  }
};

template <ll ModVal>
ostream& operator<<(ostream& os, const ModInt<ModVal>& a) {
  os << a.x;
  return os;
}

using mint = ModInt<mod>;

template <typename T>
class Combination {
 public:
  Combination(ll _max_n) : max_n(_max_n), factional(max_n + 1), inv(max_n + 1) {
    factional[0] = 1;
    inv[0] = 1;
    for (ll i = 0; i < max_n; i++) {
      factional[i + 1] = factional[i] * (i + 1); // n!(mod M)
      inv[i + 1] = inv[i] / (i + 1);             // k!^(M-2) (mod M)
    }
  }

  // nCk
  T choose(ll n, ll k) {
    if (n == 0 && k == 0)
      return 1;
    if (n < k || n < 0)
      return 0;
    T tmp = inv[n - k] * inv[k];
    return tmp * factional[n];
  }

  T permutation(ll n, ll k) {
    if (n - k < 0) {
      return 0;
    }
    return factional[n] / factional[n - k];
  }

 private:
  const ll max_n;
  std::vector<T> factional;
  std::vector<T> inv;
};

using Comb = Combination<mint>;

using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;

template <typename T>
struct Edge {
  int to;
  T cost;
};

// Dijkstra
template <typename T>
class Dijkstra {
 public:
  vector<vector<Edge<T>>> G;
  vector<vector<Edge<T>>> rev;
  int num_v;

 public:
  Dijkstra(int num_v) : G(num_v), rev(num_v), num_v(num_v) {
  }

  void add_edge(int from, int to, T cost) {
    G[from].push_back((Edge<T>){to, cost});
    rev[to].push_back((Edge<T>){from, cost});
  }

  // start: Start point
  // result: result
  void solve(int start, vector<T>& result) {
    vector<int> tmp;
    solve(start, result, tmp);
  }

  void solve(int start, vector<T>& result, vector<int>& prev) {
    result.resize(num_v);
    std::fill(result.begin(), result.end(), INF);

    prev.resize(num_v);
    std::fill(prev.begin(), prev.end(), -1);

    // get<0>(T): cost
    // get<1>(T): index
    // get<2>(T): ... ( for extent)
    using Tup = tuple<T, int>;
    priority_queue<Tup, vector<Tup>, greater<Tup>> que;

    que.emplace(0, start);
    result[start] = 0;

    while (!que.empty()) {
      Tup p = que.top();
      que.pop();

      T t = get<0>(p);
      int v = get<1>(p);

      // queueに入れてから別の最短経路が見つかった場合、探索処理は不要
      if (result[v] != t) {
        continue;
      }

      // vの各辺に対しよりコストの低い経路があるかを確認
      for (auto& e : G[v]) {
        if (result[e.to] > result[v] + e.cost) {
          prev[e.to] = v;
          result[e.to] = result[v] + e.cost;
          que.emplace(result[v] + e.cost, e.to);
        }
      }
    }
  }

  // t: 目的地
  vector<int> get_path(const vector<int>& prev, int t) {
    vector<int> path;

    for (int v = t; v != -1; v = prev[v]) {
      path.push_back(v);
    }

    reverse(path.begin(), path.end());
    return path;
  }

  void get_all_path(int start, int goal, const vector<T>& min_cost, vector<vector<int>>& next_v) {
    next_v = vector<vector<int>>(num_v);

    queue<ll> que;
    que.push(goal);

    vector<bool> visited(num_v);
    visited[goal] = true;

    while (!que.empty()) {
      ll now = que.front();
      que.pop();

      for (auto& e : rev[now]) {
        if (min_cost[now] == min_cost[e.to] + e.cost) {
          next_v[e.to].push_back(now);
          if (!visited[e.to]) {
            que.push(e.to);
            visited[e.to] = true;
          }
        }
      }
    }
  }

#ifdef USE_MODINT
  void get_path_pattern(int start, int goal, const vector<T>& min_cost, vector<mint>& ptn) {
    ptn = vector<mint>(num_v);
    ptn[start] = 1;

    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> que;
    for (int i = 0; i < num_v; i++) {
      que.emplace(min_cost[i], i);
    }

    while (!que.empty()) {
      auto [c, v] = que.top();
      que.pop();
      for (const auto e : G[v]) {
        if (min_cost[e.to] == min_cost[v] + e.cost) {
          ptn[e.to] += ptn[v];
        }
      }
    }
  }
#endif
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n, m;
  cin >> n >> m;
  Dijkstra<ll> g(n);

  ll s, t;
  cin >> s >> t;
  s--;
  t--;

  rep(i, m) {
    ll u, v, d;
    cin >> u >> v >> d;
    u--;
    v--;
    g.add_edge(u, v, d);
    g.add_edge(v, u, d);
  }

  vll cost_st;
  vm ptn_st;
  g.solve(s, cost_st);
  g.get_path_pattern(s, t, cost_st, ptn_st);

  vll cost_ts;
  vm ptn_ts;
  g.solve(t, cost_ts);
  g.get_path_pattern(t, s, cost_ts, ptn_ts);

  mint ans = ptn_st[t] * ptn_ts[s];

  vector<mint> ptn(n);
  ptn[s] = 1;

  priority_queue<pair<ll, int>> que;
  que.emplace(cost_st[t], t);

  vb visited(n);
  visited[t] = true;

  while (!que.empty()) {
    auto [c, v] = que.top();
    que.pop();

    if (cost_st[v] * 2 == cost_st[t]) {
      mint p = ptn_st[v] * ptn_ts[v];
      ans -= p * p;
      continue;
    }

    for (const auto e : g.rev[v]) {
      if (cost_st[e.to] == cost_st[v] - e.cost) {
        if (cost_st[e.to] * 2 < cost_st[t]) {
          mint p = ptn_st[e.to] * ptn_ts[v];
          ans -= p * p;
          continue;
        }

        if (!visited[e.to]) {
          que.emplace(cost_st[e.to], e.to);
          visited[e.to] = true;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
