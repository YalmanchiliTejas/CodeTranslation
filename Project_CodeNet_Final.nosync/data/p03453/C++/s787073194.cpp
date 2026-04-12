#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>

using namespace std;
using namespace boost::adaptors;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

using Weight = ll;
Weight INF = 1000000000000000l;
struct Edge{
  int src, dest; Weight weight;
  bool operator < (const Edge &rhs) const {return weight > rhs.weight;}
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

void add_edge(Graph &g, int src, int dest, Weight weight) {
  g[src].push_back((Edge){src, dest, weight});
}

// Dijkstra (Verified: AOJ2005)
void dijkstra(Graph &g, Array &d, int s) {
  d.assign(g.size(), INF);
  d[s] = 0;
  using P = pair<Weight,int>;
  priority_queue<P, vector<P>, greater<P> > que;
  que.push(P(0, s));
  while (!que.empty()) {
    Weight dist = que.top().first;
    int v = que.top().second;
    que.pop();
    if (d[v] < dist) continue;
    for(auto&& i:irange(0ul,g[v].size())){
      Edge e = g[v][i];
      if (d[e.dest] > d[v] + e.weight) {
        d[e.dest] = d[v] + e.weight;
        que.push(P(d[e.dest], e.dest));
      }
    }
  }
}

constexpr ll MOD = 1000000007;

ll dfs(const Graph& g, vecll& cnt, int i) {
  if (cnt[i] >= 0) return cnt[i];
  ll sum = 0;
  for(auto&& e:g[i]) {
    sum += dfs(g, cnt, e.dest);
    sum %= MOD;
  }
  return cnt[i] = sum;
}

int main()
{
  int n,m;
  cin>>n>>m;
  int s,t;
  cin>>s>>t;
  --s;--t;
  Graph g(n);
  Edges ve;
  for(auto&& i:irange(0,m)) {
    int u,v;
    cin>>u>>v;
    ll d;
    cin>>d;
    --u;--v;
    add_edge(g, u, v, d);
    add_edge(g, v, u, d);
    ve.push_back(Edge{u, v, d});
  }
  Array ds;
  dijkstra(g, ds, s);
  Array dt;
  dijkstra(g, dt, t);
  ll st = ds[t];
  Graph g2(n);
  Graph g3(n);
  Edges vme;
  for(auto&& e:ve) {
    int src = e.src, dest = e.dest;
    if (ds[src] > ds[dest]) swap(src, dest);
    if (ds[src] + e.weight != ds[dest]) continue;
    if (dt[dest] + e.weight != dt[src]) continue;
    if (ds[src] + dt[src] != st) continue;
    if (ds[dest] + dt[dest] != st) continue;
    add_edge(g2, src, dest, e.weight);
    add_edge(g3, dest, src, e.weight);
    vme.push_back(Edge{src, dest, e.weight});
  }
  vecll cntt(n, -1);
  cntt[t] = 1;
  dfs(g2, cntt, s);
  vecll cnts(n, -1);
  cnts[s] = 1;
  dfs(g3, cnts, t);
  ll total = cntt[s] * cnts[t] % MOD;
  for (auto&& i:irange(0,n)) {
    if (ds[i] == dt[i] && ds[i] + dt[i] == st) {
      ll tmp = cntt[i] * cnts[i] % MOD;
      tmp *= tmp;
      tmp %= MOD;
      total += MOD - tmp;
      total %= MOD;
    }
  }
  for (auto&& e:vme) {
    if (2 * ds[e.src] >= st || 2 * ds[e.dest] <= st) continue;
    ll tmp = cnts[e.src] * cntt[e.dest] % MOD;
    tmp *= tmp;
    tmp %= MOD;
    total += MOD - tmp;
    total %= MOD;
  }
  cout<<total<<endl;
  return 0;
}
