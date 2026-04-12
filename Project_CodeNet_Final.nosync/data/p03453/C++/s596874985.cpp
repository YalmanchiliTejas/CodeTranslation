#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using Pi = pair<int, int>;
using Tapris = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

struct edge {
  int to, cost;
  edge(){}
  edge(int to, int cost):to(to), cost(cost){}
};

using Graph = vector<vector<edge> >;

vint dijkstra(int s, const Graph& g) {
  int n = g.size();
  vint res(n, inf);
  priority_queue<Pi, vector<Pi>, greater<Pi> > que;
  res[s] = 0;
  que.emplace(0, s);
  while(!que.empty()) {
    Pi p = que.top(); que.pop();
    int v = p.second;
    if(res[v] < p.first) continue;
    for(auto&& e : g[v]) {
      if(res[v]+e.cost < res[e.to]) {
	res[e.to] = res[v]+e.cost;
	que.emplace(res[e.to], e.to);
      }
    }
  }
  return res;
}

struct TopoSort {
  TopoSort(){}
  void bfs(const Graph& graph, vint& in, vint& used, vint& res, int s) {
    queue<int> que;
    que.push(s);
    used[s] = 1;
    while(!que.empty()) {
      int u = que.front(); que.pop();
      res.push_back(u);
      for(auto&& e : graph[u]) {
	int v = e.to;
	--in[v];
	if(!in[v] && !used[v]) {
	  que.push(v);
	  used[v] = 1;
	}
      }
    }
  }
  vint sort(const Graph& graph) {
    vint res;
    int V = graph.size();
    vint in(V, 0), used(V, 0);
    for(int u = 0; u < V; u++) {
      for(auto&& e : graph[u]) in[e.to]++;
    }
    for(int u = 0; u < V; u++) {
      if(!in[u] && !used[u]) bfs(graph, in, used, res, u);
    }
    return res;
  }
};

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int n, m, s, t;
  cin >> n >> m >> s >> t;
  --s, --t;
  Graph graph(n);
  vint u(m), v(m), c(m);
  rep(i, m) {
    cin >> u[i] >> v[i] >> c[i];
    --u[i], --v[i];
    graph[u[i]].emplace_back(v[i], c[i]);
    graph[v[i]].emplace_back(u[i], c[i]);
  }
  vint ds = dijkstra(s, graph);
  vint dt = dijkstra(t, graph);
  int dist = ds[t];
  assert(ds[t] == dt[s]);
  Graph dag(n), rdag(n);
  vint used(m);
  rep(i, m) {
    if(ds[u[i]]+dt[v[i]]+c[i] == dist) {
      dag[u[i]].emplace_back(v[i], c[i]);
      rdag[v[i]].emplace_back(u[i], c[i]);
      used[i] = 1;
    } else if(ds[v[i]]+dt[u[i]]+c[i] == dist) {
      dag[v[i]].emplace_back(u[i], c[i]);
      rdag[u[i]].emplace_back(v[i], c[i]);
      used[i] = -1;
    }
  }
  auto id = TopoSort().sort(dag);
  vint dp(n);
  //cout<<dist<<endl;
  //cout<<s<<" "<<id[0]<<" "<<t<<" "<<id.back()<<endl;
  //assert(s == id[0] && t == id.back());
  //dp[id[0]] = 1;
  dp[s] = 1;
  for(auto&& i : id) {
    for(auto&& e : dag[i]) {
      dp[e.to] += dp[i];
      dp[e.to] %= mod;
    }
  }
  auto rid = TopoSort().sort(rdag);
  vint rdp(n);
  //assert(s == rid.back() && t == rid[0]);
  //rdp[rid[0]] = 1;
  rdp[t] = 1;
  for(auto&& i : rid) {
    for(auto&& e : rdag[i]) {
      rdp[e.to] += rdp[i];
      rdp[e.to] %= mod;
    }
  }
  int ans = dp[t]*rdp[s]%mod;
  int sub = 0;
  for(auto&& i : id) {
    if(dist%2 == 0 && ds[i] == dist/2) {
      int tmp = dp[i]*rdp[i]%mod;
      sub += tmp*tmp%mod;
      sub %= mod;
    }
    if(ds[i]*2 >= dist) continue;
    for(auto&& e : dag[i]) {
      if(ds[e.to]*2 > dist) {
	int tmp = dp[i]*rdp[e.to]%mod;
	sub += tmp*tmp%mod;
	sub %= mod;
      }
    }
  }
  cout << (ans-sub+mod)%mod << endl;

  return 0;
}

