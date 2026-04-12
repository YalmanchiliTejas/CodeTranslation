#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rep(i, s, N) for (ll i{s}; i < (N); i++)
#define rem(i, N, s) for (ll i{N}; i > (s); i--)
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugp(i) cerr << "(" << i.first << ", " << i.second << ")\n"
#define debugv(v) cerr << #v << ": ";for(auto&& i : v) cerr << i << " "; cerr << '\n'
#define debugvp(v) cerr << #v << ": ";for(auto&& i : v) cerr << "(" << i.first << ", " << i.second << ") "; cerr << '\n'
const int MOD = (int)1e9 + 7;
const long double pi = 3.141592653589793238462643383279L;
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using wstr = wstring;
const string rt = "\n", sp = " ";
const wstring wrt = L"\n", wsp = L" ";

/* GCD */
template <typename M, typename N>
constexpr common_type_t<M, N> gcd(M a, N b) { return b != 0 ? gcd(b, a % b) : a; }

/* LCM */
template <typename M, typename N>
constexpr common_type_t<M, N> lcm(M a, N b) { return a * b / gcd(a, b); }

/* UNIONFIND */
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
auto comb(ll N){
  vector<vector<ll>> v(N+1,vector<ll>(N+1));
  for(unsigned int i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(unsigned int k = 1;k <v.size();k++){
    for(unsigned int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
  return v;
}
auto comb(ll N, ll n){
  vector<vector<ll>> v(max(N+1,n+1),vector<ll>(max(N+1,n+1)));
  for(unsigned int i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(unsigned int k = 1;k <v.size();k++){
    for(unsigned int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
  return v[N][n];
}

/* COMB % MOD */
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
constexpr vector<T> make_vector(size_t a) { return vector<T>(a); }
template <class T, class... Ts>
auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...)); }

/* MAKE DEQUE */
template <class T>
constexpr deque<T> make_deque(size_t a) { return deque<T>(a); }
template <class T, class... Ts>
auto make_deque(size_t a, Ts... ts) { return deque<decltype(make_deque<T>(ts...))>(a, make_deque<T>(ts...)); }

/* TEST */
void test(ll n) { cout << "test" << n << endl; }

/* PRECISION */
void fixsp(ll n) { cout << fixed << setprecision(n); }
void defsp(ll n) { cout << defaultfloat << setprecision(n); }

/* WEIGHTENED UNIONFIND */
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
T multi(T a, ll b)
{
  T ans{1};
  for (int i{}; i < b; i++)
    ans *= a;
  return ans;
}

/* INF */
template <typename T>
constexpr T inf() { return numeric_limits<T>::max(); } 

/* FASTER IO */
void fastio(ll a)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  if(a) fixsp(a);
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

/* BELLMANFORD */

vector<long long> BellmanFord(int s, int V, vector<tuple<long long,long long,long long>> &G)
{
  vector<long long> d(V, inf<long long>());
  vector<bool> neg(V);
  d[s] = 0;
  for (int i = 0; i < V - 1; ++i)
  {
    for (auto &&e : G)
    {
      if (d[get<0>(e)] == inf<long long>())
        continue;
      d[get<1>(e)] = min(d[get<1>(e)], d[get<0>(e)] + get<2>(e));
    }
  }
  for (int i = 0; i < V; ++i)
  {
    for (auto &&e : G)
    {
      if (d[get<0>(e)] == inf<long long>())
        continue;
      if (d[get<1>(e)] > d[get<0>(e)] + get<2>(e))
      {
        d[get<1>(e)] = d[get<0>(e)] + get<2>(e);
        neg[get<1>(e)] = 1;
      }
      if (neg[get<0>(e)])
        neg[get<1>(e)] = 1;
    }
  }
  for (int i = 0; i < V; i++)
  {
    if (neg[i])
      d[i] = -inf<long long>();
  }
  return d;
}

/* DIJKSTRA */

vector<long long> Dijkstra(int s, int V, vector<tuple<long long,long long,long long>> &G){
  vector<vector<pair<long long,long long>>> uv(V);
  for(auto&& i : G) uv[get<0>(i)].emplace_back(get<1>(i), get<2>(i));
  vector<long long> d(V, inf<long long>()/2);
  vector<long long> prev(V, -1);
  d[s] = 0;
  priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> Q;
  rep(i,0,V) Q.emplace(d[i], i);
  while(!Q.empty()){
    long long u = Q.top().second;
    Q.pop();
    for(auto&& v : uv[u]){
      long long alt = d[u] + v.second;
      if(d[v.first] > alt){
        d[v.first] = alt;
        if(d[v.first] > inf<long long>()/4) d[v.first] = inf<long long>()/2;
        else if(d[v.first] < -inf<long long>()/4) d[v.first] = -inf<long long>()/2;
        prev[v.first] = u;
        Q.emplace(alt, v.first);
      }
    }
  }
  for(auto&& i : d){
    if(abs(i)>inf<long long>()/4) (i*=2)++;
  }
  return d;
}

/* BFS */

vector<long long> BFS(long long s, long long V, vector<pair<long long,long long>> &G){
  queue<long long> Q;
  vector<vector<long long>> uv(V);
  for(auto&& i : G) uv[i.first].emplace_back(i.second);
  vector<long long> d(V,inf<long long>());
  d[s] = 0;
  Q.emplace(s);
  while(!Q.empty()){
    long long v = Q.front();
    Q.pop();
    for(auto&& i : uv[v]){
      if(d[i] == inf<long long>()){
        d[i] = d[v]+1;
        Q.emplace(i);
      }
    }
  }
  return d;
}

/* WARSHALLFLOYD */
vector<vector<long long>> WarshallFloyd(int V, vector<tuple<long long,long long,long long>> &G){
  vector<vector<long long>> d(V, vector<long long>(V, inf<long long>()));
  for(auto&& i : G){
    d[get<0>(i)][get<1>(i)] = get<2>(i);
  }
  rep(k,0,V) rep(i,0,V) rep(j,0,V){
    if(d[i][k] != inf<ll>() && d[k][j] != inf<ll>())
    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  }
  rep(i,0,V){
    d[i][i] = 0;
  }
  return d;
}

/* NUITA.INC & KYOTO UNIVERSITY */

/* LAST EDITED ON 9.5.2019 */

/* CODE STARTS FROM HERE */

int main(){
  fastio(0);
  ll X, Y, Z;
  cin >> X >> Y >> Z;
  cout << (X-Z)/(Y+Z) << rt;
}