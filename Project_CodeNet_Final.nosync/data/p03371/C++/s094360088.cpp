#include <bits/stdc++.h>
const int MOD = (int)1e9 + 7;
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
const string rt = "\n", sp = " ";
/* GCD */
template <typename M, typename N>
constexpr common_type_t<M, N> gcd(M a, N b) { return b != 0 ? gcd(b, a % b) : a; } /* LCM */
template <typename M, typename N>
constexpr common_type_t<M, N> lcm(M a, N b) { return a * b / gcd(a, b); } /* UnionFind */
template <typename T>
struct UnionFind
{
  vector<T> par;
  UnionFind(T n) : par(n, -1) {}
  void init(T n) { par.assign(n, -1); }
  T root(T x)
  {
    if (par[x] < 0)
      return x;
    else
      return par[x] = root(par[x]);
  }
  bool issame(T x, T y) { return root(x) == root(y); }
  bool merge(T x, T y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (par[x] > par[y])
      swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }
  int size(int x) { return -par[root(x)]; }
};
/* COMB */
ll comb(ll n, ll r)
{
  if (n < r)
    return 0;
  if (r * 2 > n)
    r = n - r;
  ll dividend = 1;
  ll divisor = 1;
  for (ll i = 1; i <= r; ++i)
  {
    dividend *= (n - i + 1);
    divisor *= i;
  }
  return dividend / divisor;
} /* COMB % MOD */
template <typename T>
ll combpm(T N_, T C_)
{
  const int NUM_ = 400001;
  static ll fact[NUM_ + 1], factr[NUM_ + 1], inv[NUM_ + 1];
  if (fact[0] == 0)
  {
    inv[1] = fact[0] = factr[0] = 1;
    for (int i = 2; i <= NUM_; ++i)
      inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
    for (int i = 1; i <= NUM_; ++i)
      fact[i] = fact[i - 1] * i % MOD, factr[i] = factr[i - 1] * inv[i] % MOD;
  }
  if (C_ < 0 || C_ > N_)
    return 0;
  return factr[C_] * fact[N_] % MOD * factr[N_ - C_] % MOD;
}
/* MAKE VECTOR */
template <class T>
constexpr vector<T> mvec(size_t a) { return vector<T>(a); }
template <class T, class... Ts>
auto mvec(size_t a, Ts... ts) { return vector<decltype(mvec<T>(ts...))>(a, mvec<T>(ts...)); } /* MAKE DEQUE */
template <class T>
constexpr deque<T> mdeq(size_t a) { return deque<T>(a); }
template <class T, class... Ts>
auto mdeq(size_t a, Ts... ts) { return deque<decltype(mdeq<T>(ts...))>(a, mdeq<T>(ts...)); } /* TEST */
void test(ll n) { cout << "test" << n << endl; }                                             /* PRECISION */
void fixsp(ll n) { cout << fixed << setprecision(n); }
void defsp(ll n) { cout << defaultfloat << setprecision(n); } /* WEIGHTENED UnionFind */
struct WUnionFind
{
  vector<int> par;
  vector<int> rank;
  WUnionFind(int n = 1) { init(n); }
  void init(int n = 1)
  {
    par.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; ++i)
      par[i] = i, rank[i] = 0;
  }
  int root(int x)
  {
    if (par[x] == x)
    {
      return x;
    }
    else
    {
      int r = root(par[x]);
      return par[x] = r;
    }
  }
  bool issame(int x, int y) { return root(x) == root(y); }
  bool merge(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (rank[x] < rank[y])
      swap(x, y);
    if (rank[x] == rank[y])
      ++rank[x];
    par[y] = x;
    return true;
  }
};
/* DIVISOR */
deque<ll> divisor(ll n)
{
  deque<ll> ret;
  for (ll i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      ret.push_back(i);
      if (i * i != n)
        ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}
/* MODE */
template <typename T>
auto mode(T data)
{
  if (data.size() == 1)
    return *begin(data);
  sort(begin(data), end(data));
  typename decltype(data)::value_type mode{};
  size_t n{}, count{1};
  for (auto iter = adjacent_find(begin(data), end(data)), last = end(data), next = end(data); iter != last;)
  {
    next = upper_bound(iter, last, *iter);
    count = distance(iter, next);
    if (n < count)
      n = count, mode = *iter;
    iter = adjacent_find(next, last);
  }
  return mode;
}
/* MEDIAN */
template <typename T>
auto median(T data)
{
  sort(begin(data), end(data));
  size_t median_index = data.size() / 2;
  return (data.size() % 2 == 0 ? static_cast<double>(data[median_index] + data[median_index - 1]) / 2 : data[median_index]);
}
/* INT POW */
template <typename T>
ll multi(T a, T b)
{
  ll ans{1};
  for (int i{}; i < b; i++)
    ans *= a;
  return ans;
} /* INF */
template <typename T>
constexpr T inf() { return numeric_limits<T>::max(); } /* FASTER IO */
void fastio()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}
/* MIN COST FLOW */
template <typename flow_t, typename cost_t>
struct PrimalDual
{
  const cost_t INF;
  struct edge
  {
    int to;
    flow_t cap;
    cost_t cost;
    int rev;
    bool isrev;
  };
  vector<vector<edge>> graph;
  vector<cost_t> potential, min_cost;
  vector<int> prevv, preve;
  PrimalDual(int V) : graph(V), INF(numeric_limits<cost_t>::max()) {}
  void add_edge(int from, int to, flow_t cap, cost_t cost)
  {
    graph[from].emplace_back((edge){to, cap, cost, (int)graph[to].size(), false});
    graph[to].emplace_back((edge){from, 0, -cost, (int)graph[from].size() - 1, true});
  }
  cost_t min_cost_flow(int s, int t, flow_t f)
  {
    int V = (int)graph.size();
    cost_t ret = 0;
    using Pi = pair<cost_t, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> que;
    potential.assign(V, 0);
    preve.assign(V, -1);
    prevv.assign(V, -1);
    while (f > 0)
    {
      min_cost.assign(V, INF);
      que.emplace(0, s);
      min_cost[s] = 0;
      while (!que.empty())
      {
        Pi p = que.top();
        que.pop();
        if (min_cost[p.second] < p.first)
          continue;
        for (int i = 0; i < graph[p.second].size(); i++)
        {
          edge &e = graph[p.second][i];
          cost_t nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
          if (e.cap > 0 && min_cost[e.to] > nextCost)
          {
            min_cost[e.to] = nextCost;
            prevv[e.to] = p.second, preve[e.to] = i;
            que.emplace(min_cost[e.to], e.to);
          }
        }
      }
      if (min_cost[t] == INF)
        return -1;
      for (int v = 0; v < V; v++)
        potential[v] += min_cost[v];
      flow_t addflow = f;
      for (int v = t; v != s; v = prevv[v])
      {
        addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
      }
      f -= addflow;
      ret += addflow * potential[t];
      for (int v = t; v != s; v = prevv[v])
      {
        edge &e = graph[prevv[v]][preve[v]];
        e.cap -= addflow;
        graph[v][e.rev].cap += addflow;
      }
    }
    return ret;
  }
  void output()
  {
    for (int i = 0; i < graph.size(); i++)
    {
      for (auto &e : graph[i])
      {
        if (e.isrev)
          continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << rev_e.cap + e.cap << ")" << endl;
      }
    }
  }
};
/* BELLMAN = FORD */
template <typename T>
struct edge
{
  int from, to;
  T cost;
  edge(int to, T cost) : from(-1), to(to), cost(cost) {}
  edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
  explicit operator int() const { return to; }
};
template <typename T>
vector<T> BellmanFord(int s, int V, vector<edge<T>> &G)
{
  vector<T> d(V, inf<T>());
  vector<bool> neg(V);
  d[s] = 0;
  for (int i = 0; i < V - 1; ++i)
  {
    for (auto &&e : G)
    {
      if (d[e.from] == inf<T>())
        continue;
      d[e.to] = min(d[e.to], d[e.from] + e.cost);
    }
  }
  for (int i = 0; i < V; ++i)
  {
    for (auto &&e : G)
    {
      if (d[e.from] == inf<T>())
        continue;
      if (d[e.to] > d[e.from] + e.cost)
      {
        d[e.to] = d[e.from] + e.cost;
        neg[e.to] = 1;
      }
      if (neg[e.from])
        neg[e.to] = 1;
    }
  }
  for (int i = 0; i < V; i++)
  {
    if (neg[i])
      d[i] = -inf<ll>();
  }
  return d;
}
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rep(i, s, N) for (ll i{s}; i < (N); i++)
#define rem(i, N, s) for (ll i{N}; i > (s); i--)

/* FACULTY OF SCIENCE, KYOTO UNIVERSITY */

/* CODE STARTS FROM HERE */

int main(){
  fastio();
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  cout << min({C*2*max(X,Y) + A*max(X-max(X,Y),0LL) + B*max(Y-max(X,Y),0LL),C*2*min(X,Y) + A*max(X-min(X,Y),0LL) + B*max(Y-min(X,Y),0LL), A*X + B*Y});
}