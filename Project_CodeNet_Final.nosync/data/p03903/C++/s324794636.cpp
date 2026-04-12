#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<LL, LL> PLL;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

class UnionFind{
private:
  vector<int> par, rank;
public:
  UnionFind(int n){
	par.assign(n, 0);
	rank.assign(n, 0);
	for(int i=0;i<n;++i)
	  par[i] = i;
  }

  //find root of x
  int find(int x){
	if(par[x] == x)
	  return x;
	return (par[x] = find(par[x]));
  }

  void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return;

	if(rank[x] < rank[y])
	  par[x] = y;
	else{
	  par[y] = x;
	  if(rank[x] == rank[y])
		++rank[x];
	}
  }

  bool same(int x, int y){
	return find(x) == find(y);
  }
};

struct Edge{
  int to;
  LL cost;

  Edge(int t, LL c): to(t), cost(c)
  {}
  bool operator>(const Edge& rhs) const{
	return cost > rhs.cost;
  }
  bool operator<(const Edge& rhs) const{
	return cost < rhs.cost;
  }

};
typedef vector< vector<Edge> > Graph;

// 無向グラフのとき
void add_edge(Graph& graph, int u, int v, LL cost){
  graph[u].push_back(Edge(v,cost));
  graph[v].push_back(Edge(u,cost));
}

vector<pair<Edge,int>> edges;
LL kruskal(const Graph& G, Graph& G_){
  int N = SZ(G);
  UnionFind uf(N);

  LL res = 0, i, n = 0;
  for(i=0;i<SZ(edges);++i){
	auto& e = edges[i].first;
	int v = edges[i].second;
	if(!uf.same(e.to,v)){
	  uf.unite(e.to, v);
	  res += e.cost;
	  add_edge(G_, e.to, v, e.cost);
	}
  }
  return res;
}

LL dist[4010][4010];
void dfs(int s, int p, int u, LL mx, Graph& G){
  dist[s][u] = dist[u][s] = max(dist[s][u], mx);
  for(auto& e: G[u]){
	if(e.to == p) continue;
	dfs(s, u, e.to, max(mx,e.cost), G);
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  Graph G(N), G_(N);
  REP(i,M){
	int a, b, c; cin >> a >> b >> c;
	--a; --b;
	add_edge(G, a, b, c);
	edges.push_back(MP(G[a].back(), a));
	edges.push_back(MP(G[b].back(), b));
  }
  sort(ALL(edges));

  LL mx = kruskal(G,G_);
  REP(i,N) dfs(i,-1,i,0,G_);
  int Q; cin >> Q;
  while(Q--){
	LL s,t; cin >> s >> t;
	--s, --t;

	cout << mx - dist[s][t] << endl;
  }

  return 0;
}
