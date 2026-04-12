#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
  #include "_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

struct UnionFind{
  vector<int> par; //親
  vector<int> size; //集合の大きさ

  UnionFind(int n){
    par.resize(n); size.resize(n, 1);
    for(int i = 0; i < n; i++){
      par[i] = i;
    }
  }

  //木の根を求める
  int root(int x){
    if(par[x] == x){
      return x;
    }else{
      return par[x] = root(par[x]);
    }
  }

  //xとyの属する集合を併合
  void unite(int x,int y){
    x = root(x), y = root(y);
    if(x == y) return;
    if(size[x] < size[y]) swap(x,y);
    par[y] = x;
    size[x] += size[y];
  }

  bool same(int x, int y){
    return root(x) == root(y);
  }
};

struct edge{ 
  int from, to, cost;
  bool operator<(const edge& p) const {
    return cost < p.cost;
  }
  bool operator>(const edge& p) const {
    return cost > p.cost;
  }
};

vector<int> dikstra(vector<vector<edge>> G, int s){
  using P = pair<int, int>;
  priority_queue<P,vector<P>,greater<P>> q;
  vector<int> d(G.size(), 1LL << 60); //sからの最短距離
  d[s] = 0;
  q.push({0, s}); //{最短距離,頂点}

  while(!q.empty()){
    auto p = q.top(); q.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(auto e : G[v]){
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        q.push(P(d[e.to], e.to));
      }
    }
  }
  return d;
}

template<class T> vector<T> make_vec(size_t a) { return vector<T>(a); }
template<class T, class... Ts> auto make_vec(size_t a, Ts... ts) {
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template<class T, class V>
typename enable_if<is_class<T>::value == 0>::type fill(T &t, const V &v) {
    t = v;
}
template<class T, class V>
typename enable_if<is_class<T>::value != 0>::type fill(T &t, const V &v) {
    for (auto &e : t) fill(e, v);
}
// auto v = make_vec<int>(h, w);
// fill(v, 0);

using P = pair<int, int>;

signed main(){

  int n, m; cin >> n >> m;
  map<P, int> mp;
  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    a--, b--;
    if(mp.find(P(a, b)) == mp.end()){
      mp[P(a, b)] = c;
    }else{
      mp[P(a, b)] = min(mp[P(a, b)], c);
    }
  }
  vector<edge> es;
  for(auto p : mp){
    int a = p.first.first, b = p.first.second, c = p.second;
    es.push_back({a, b, c});
    es.push_back({b, a, c});
  }

  sort(es.begin(), es.end());
  int total = 0;
  struct E { int to, cost; };
  vector<vector<E>> g(n);
  UnionFind uf(n);
  for(auto e : es){
    int u = e.from, v = e.to, cost = e.cost;
    if(!uf.same(u, v)){
      total += cost;
      uf.unite(u, v);
      g[u].push_back({v, cost});
      g[v].push_back({u, cost});
    }
  }

  auto dp = make_vec<int>(n, n);
  int start;
  auto dfs = [&](auto&& dfs, int u, int par, int Max)->void{
    dp[start][u] = Max;
    for(auto e : g[u]){
      if(!(par == e.to)){
        dfs(dfs, e.to, u, max(Max, e.cost));
      }
    }
  };
  for(int i = 0; i < n; i++){
    start = i;
    dfs(dfs, i, -1, 0);
  }

  int q; cin >> q;
  for(int i = 0; i < q; i++){
    int u, v; cin >> u >> v;
    u--, v--;
    int ans = total - dp[u][v];
    cout << ans << endl;
  }

  return 0;
}