#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<functional>
#include<cstring>
using namespace std;

/**** Type Define ****/

typedef long long ll;
typedef pair<ll, ll> P;

/**** Const List   ****/

const ll INF = ((ll)1 << 31) - 1;
const ll DINF = (ll)1e20;
const ll UNION_FIND_MAX = 100000;
const ll SEGMENT_TREE_MAX = (1 << 18) - 1;
const ll MAX_FLOW_MAX_V = 10000;
const ll MIN_COST_FLOW_MAX_V = 10000;
const ll BIPARTITE_MATCHING_MAX_V = 10000;
const ll DIJKSTRA_MAX_V = 1000000;


/**** General Functions ****/

template <typename T>
T tmin(T a, T b) { return a > b ? b : a; };

template <typename T>
T tmax(T a, T b) { return a > b ? a : b; };

template <typename T>
T tadd(T a, T b) { return a + b; };

template <typename T>
T tmul(T a, T b) { return a * b; };

template <typename T>
T tpow(T a, T b) { return a * b; };

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll lmin(ll a, ll b) { return a > b ? b : a; };

ll lmax(ll a, ll b) { return a > b ? a : b; };


/**** Dijkstra ****/
class Dijkstra { // double は無理!!
public:
  struct edge { ll to, cost; };

  ll V;
  vector<edge> G[DIJKSTRA_MAX_V];
  ll d[DIJKSTRA_MAX_V];
  priority_queue<P, vector<P>, greater<P> > que;

  Dijkstra() {}
  Dijkstra(ll v) {
    init(v);
  }
  void init(ll v) {
    V = v;
    for (ll i = 0; i < v; i++) {
      G[i].clear();
    }
  }
  void search(ll from) {
    for (ll i = 0; i < V; i++) d[i] = INF;
    d[from] = 0;
    que.push(P(0, from));
    while (!que.empty()) {
      P p = que.top(); que.pop();
      ll b = p.second;
      ll c = p.first;
      if (d[b] <= c) continue;
      for (ll i = 0; i < G[b].size(); i++) {
        edge e = G[b][i];
        ll nc = c + e.cost;
        ll nt = e.to;
        if (d[nt] > nc) que.push(P(nc, nt)), d[nt] = nc;
      }
    }
  }
};

/**** Matrix ****/

template <typename T>
struct Matrix {
  typedef vector<T> vec;
  typedef vector<vec> mat;
  ll x, y; // x: horizon  y: vertical
  mat d;

  Matrix(ll _y, ll _x = -1) {
    if (_x == -1) _x = _y;
    x = _x, y = _y;
    for (int i = 0; i < y; i++) for (int j = 0; j < x; j++) d[i][j] = 0;
  }
  void unit() {
    for (int i = 0; i < y; i++) for (int j = 0; j < x; j++) d[i][j] = i == j ? 1 : 0;
  }
  Matrix copy() {
    Matrix m(y, x);
    for (int i = 0; i < y; i++) for (int j = 0; j < x; j++) m.d[i][j] = d[i][j];
    return m;
  }
  Matrix<T> operator + (Matrix<T>& t) { // No error check! Don't forget to check Matrix size!!
    Matrix<T> m(y, x);
    for (int i = 0; i < y; i++) for (int j = 0; j < x; j++) m.d[i][j] = d[i][j] + t.d[i][j];
    return m;
  }
  Matrix<T> operator - (Matrix<T>& t) {
    Matrix<T> m(y, x);
    for (int i = 0; i < y; i++) for (int j = 0; j < x; j++) m.d[i][j] = d[i][j] - t.d[i][j];
    return m;
  }
  Matrix<T> operator * (T t) {
    Matrix<T> m(y, x);
    for (int i = 0; i < y; i++) for (int j = 0; j < x; j++) m.d[i][j] = d[i][j] * t;
    return m;
  }
  Matrix<T> det(Matrix<T>& t) { // x need to correspond to t.y
    Matrix<T> m(y, x);
    for (int i = 0; i < y; i++)
      for (int j = 0; j < x; j++)
        for (int k = 0; k < t.x; k++) m.d[i][j] += d[i][k] * t.d[k][j]; ////////////// mod???
    return m;
  }
};

/**** Zip ****/

template <typename T>
class Zip {
  vector<T> d;
  bool flag;
public:
  Zip() {
    flag = false;
  }
  void add(T x) {
    d.push_back(x);
    flag = true;
  }
  ll getNum(T x) { // T need to have operator < !!
    if (flag) {
      sort(d.begin(), d.end());
      d.erase(unique(d.begin(), d.end()), d.end());
      flag = false;
    }
    return lower_bound(d.begin(), d.end(), x) - d.begin();
  }
  ll size() {
    return (ll)d.size();
  }
};

/**** Union Find ****/

class UnionFind {
  ll par[UNION_FIND_MAX];
  ll rank[UNION_FIND_MAX];
public:
  void init(ll n) {
    for (ll i = 0; i < n; i++) par[i] = i, rank[i] = 0;
  }
  UnionFind(ll n) {
    init(n);
  }
  ll findRoot(ll x) {
    if (par[x] == x) return x;
    return par[x] = findRoot(par[x]);
  }
  void merge(ll x, ll y) {
    x = findRoot(x);
    y = findRoot(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }
  bool isSame(ll x, ll y) {
    return findRoot(x) == findRoot(y);
  }
};

template <typename T>
class UnionFindT {
  ll par[UNION_FIND_MAX];
  ll rank[UNION_FIND_MAX];
  T weight[UNION_FIND_MAX];
public:
  void init(ll n, T w) {
    for (ll i = 0; i < n; i++) par[i] = i, rank[i] = 0, weight[i] = w;
  }
  UnionFindT(ll n, T w) {
    init(n, w);
  }
  ll findRoot(ll x) {
    if (par[x] == x) return x;
    weight[x] += weight[par[x]];
    return par[x] = findRoot(par[x]);
  }
  T getWeight(ll x) {
    findRoot(x);
    return weight[x];
  }
  bool merge(ll x, ll y, T w) {
    // weight(y) = weight(x) + wにする
    w += weight(x);
    w -= weight(y);
    x = findRoot(x);
    y = findRoot(y);
    if (x == y) return false;
    if (rank[x] < rank[y]) {
      par[x] = y;
      weight[x] = -w;
    } else {
      par[y] = x;
      weight[y] = w;
      if (rank[x] == rank[y]) rank[x]++;
    }
    return true;
  }
  T diff(ll x, ll y) { // xが基準でyの重み
    return weight(y) - weight(x);
  }
  bool isSame(ll x, ll y) {
    return findRoot(x) == findRoot(y);
  }
};

/**** Segment Tree ****/

template <typename T>
struct SegmentTree {
  ll n;
  T dat[SEGMENT_TREE_MAX];
  function<T(T, T)> acc;
  T out;
  SegmentTree(function<T(T, T)> func, T overNum) {
    acc = func;
    out = overNum;
  }
  void init(ll _n) {
    n = 1;
    while (n < _n) n *= 2;
    for (ll i = 0; i < 2 * n - 1; i++) dat[i] = out;
  }
  void nodeUpdate(ll k, T d) {
    // k番目をdに変える
    k += n - 1;
    dat[k] = d;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = acc(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }
  T rangeQuery(ll a, ll b) {
    return tempRangeQuery(a, b, 0, 0, n);
  }

private:
  T tempRangeQuery(const ll& a, const ll& b, ll k, ll l, ll r) {
    if (r <= a || b <= l) return out;
    if (a <= l && r <= b) return dat[k];
    T vl = tempRangeQuery(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = tempRangeQuery(a, b, k * 2 + 2, (l + r) / 2, r);
    return acc(vl, vr);
  }
};

/**** Network Flow ****/

class MaxFlow {
public:
  struct edge { ll to, cap, rev; };

  vector<edge> G[MAX_FLOW_MAX_V];
  bool used[MAX_FLOW_MAX_V];
  ll level[MAX_FLOW_MAX_V];
  ll iter[MAX_FLOW_MAX_V];
  
  void init() {
    for (ll i = 0; i < MAX_FLOW_MAX_V; i++) {
      G[i].clear();
    }
  }
  void add_edge(ll from, ll to, ll cap) {
    G[from].push_back((edge){to, cap, (ll)G[to].size()});
    G[to].push_back((edge){from, 0, (ll)G[from].size() - 1});
  }
  void add_undirected_edge(ll e1, ll e2, ll cap) {
    G[e1].push_back((edge){e2, cap, (ll)G[e2].size()});
    G[e2].push_back((edge){e1, cap, (ll)G[e1].size() - 1});
  }
  ll dfs(ll v, ll t, ll f) {
    if (v == t) return f;
    used[v] = true;
    for (ll i = 0; i < (ll)G[v].size(); i++) {
      edge &e = G[v][i];
      if (!used[e.to]&& e.cap > 0) {
        ll d = dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  ll max_flow(ll s, ll t) {
    ll flow = 0;
    while (1) {
      memset(used, 0, sizeof(used));
      ll f = dfs(s, t, INF);
      if (f == 0) return flow;
      flow += f;
    }
  }
  void bfs(ll s) {
    memset(level, -1, sizeof(level));
    queue<ll> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
      ll v = que.front(); que.pop();
      for (ll i = 0; i < (ll)G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          que.push(e.to);
        }
      }
    }
  }
  ll dinic_dfs(ll v, ll t, ll f) {
    if (v == t) return f;
    for (ll &i= iter[v]; i < (ll)G[v].size(); i++) {
      edge &e = G[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) {
        ll d = dinic_dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  ll dinic(ll s, ll t) {
    ll flow = 0;
    while (1) {
      bfs(s);
      if (level[t] < 0) return flow;
      memset(iter, 0, sizeof(iter));
      ll f;
      while ((f = dinic_dfs(s, t, INF)) > 0) {
        flow += f;
      }
    }
  }
};

/**** bipartite matching ****/

class BipartiteMatching {
public:
  ll V;
  vector<ll> G[BIPARTITE_MATCHING_MAX_V];
  ll match[BIPARTITE_MATCHING_MAX_V];
  bool used[BIPARTITE_MATCHING_MAX_V];
  
  BipartiteMatching(ll v) {
    V = v;
  }
  void init(ll v) {
    V = v;
    for (ll i = 0; i < BIPARTITE_MATCHING_MAX_V; i++) {
      G[i].clear();
    }
  }
  void add_edge(ll u, ll v) {
    G[u].push_back(v);
    G[v].push_back(u);
  }
  bool dfs(ll v) {
    used[v] = true;
    for (ll i = 0; i < (ll)G[v].size(); i++) {
      ll u = G[v][i], w = match[u];
      if (w < 0 || !used[w] && dfs(w)) {
        match[v] = u;
        match[u] = v;
        return true;
      }
    }
    return false;
  }
  ll max_matching() {
    ll res = 0;
    memset(match, -1, sizeof(match));
    for (ll v = 0; v < V;v++) {
      if (match[v] < 0) {
        memset(used, 0, sizeof(used));
        if (dfs(v)) {
          res++;
        }
      }
    }
    return res;
  }
};

class MinCostFlow {
public:
  struct edge { ll to, cap, cost, rev; };

  ll V;
  vector<edge> G[MIN_COST_FLOW_MAX_V];
  ll dist[MIN_COST_FLOW_MAX_V];
  ll prevv[MIN_COST_FLOW_MAX_V];
  ll preve[MIN_COST_FLOW_MAX_V];
  ll h[MIN_COST_FLOW_MAX_V];

  MinCostFlow(ll v) {
    V = v;
  }
  void init() {
    for (ll i = 0; i < MAX_FLOW_MAX_V; i++) {
      G[i].clear();
    }
  }
  void add_edge(ll from, ll to, ll cap, ll cost) {
    G[from].push_back((edge){to, cap, cost, (ll)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (ll)G[from].size() - 1});
  }
  void add_undirected_edge(ll e1, ll e2, ll cap, ll cost) {
    add_edge(e1, e2, cap, cost);
    add_edge(e2, e1, cap, cost);
  }
  ll min_cost_flow(ll s, ll t, ll f) { // minas
    ll res = 0;
    while (f > 0) {
      fill(dist, dist + V, INF);
      dist[s] = 0;
      bool update = true;
      while (update) {
        update = false;
        for (ll v = 0; v < V; v++) {
          if (dist[v] == INF) continue;
          for (ll i = 0; i < (ll)G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
              dist[e.to] = dist[v] + e.cost;
              prevv[e.to] = v;
              preve[e.to] = i;
              update = true;
            }
          }
        }
      }
      if (dist[t] == INF) {
        return -1;
      }
      ll d = f;
      for (ll v = t; v != s; v = prevv[v]) {
        d = min(d, G[prevv[v]][preve[v]].cap);
      }
      f -= d;
      res += d * dist[t];
      for (ll v = t; v != s; v = prevv[v]) {
        edge &e = G[prevv[v]][preve[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
    }
    return res;
  }
  ll min_cost_flow_dijkstra(ll s, ll t, ll f) {
    ll res = 0;
    fill(h, h + V, 0);
    while (f > 0) {
      priority_queue<P, vector<P>, greater<P> > que;
      fill(dist, dist + V, 0);
      dist[s] = 0;
      que.push(P(0, s));
      while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
          edge &e = G[v][i];
          if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
            dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
            prevv[e.to] = v;
            preve[e.to] = i;
            que.push(P(dist[e.to], e.to));
          }
        }
      }
      if (dist[t] == INF) {
        return -1;
      }
      for (int v = 0; v < V; v++) h[v] += dist[v];
      int d = f;
      for (int v = t; v != s; v = prevv[v]) {
        d = tmin<ll>(d, G[prevv[v]][preve[v]].cap);
      }
      f -= d;
      res += d * h[t];
      for (int v = t; v != s; v = prevv[v]) {
        edge &e = G[prevv[v]][preve[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
      return res;
    }
    return 0;
  }
};

/**** main function ****/

ll n, m, a, b;
vector<ll> e[8];
bool d[8];
ll dfs(ll now, ll c) {
  if (c == n) return 1;
  d[now] = true;
  ll ans = 0;
  for (ll i = 0; i < e[now].size(); i++) {
    ll to = e[now][i];
    if (!d[to]) ans += dfs(to, c+1);
  }
  d[now] = false;
  return ans;
}

int main() {
  scanf("%lld%lld", &n, &m);
  for (ll i = 0; i < m; i++) scanf("%lld%lld", &a, &b), a--, b--, e[a].push_back(b), e[b].push_back(a);
  for (ll i = 0; i < n; i++) d[i] = false;
  printf("%lld\n", dfs(0, 1));
}
