#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using LL = long long;
using VL = vector<LL>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using VS = vector<string>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second

#define DUMP(x) cout<<#x<<":"<<(x)<<endl
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class T>
istream& operator>>(istream& is, vector<T>& xs){
  for(auto& x: xs)
	is >> x;
  return is;
}
template<class S, class T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
  return os << p.FF << " " << p.SS;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T>& xs){
  for(unsigned int i=0;i<xs.size();++i)
	os << (i?" ":"") << xs[i];
  return os;
}
template<class T>
void maxi(T& x, T y){
  if(x < y) x = y;
}
template<class T>
void mini(T& x, T y){
  if(x > y) x = y;
}


const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;
const LL INF = 1e18;

struct Edge{
  LL to, cost;

  Edge(LL t, LL c = 0): to(t), cost(c)
  {}
};
using Graph = vector<vector<Edge>>;

void add_edge(Graph& graph, int u, int v, LL cost = 0){
  graph[u].push_back(Edge(v,cost));
  graph[v].push_back(Edge(u,cost));
}
void Dijkstra(const Graph& G, vector<LL>& d, int s){
  using Type = pair<LL,LL>;
  priority_queue<Type, vector<Type>, greater<Type> > pq;
  fill(d.begin(), d.end(), INF);
  d[s] = 0;
  pq.push(MP(0,s));

  while(!pq.empty()){
	Type pii = pq.top();
	pq.pop();
	int v = pii.second;
	if(d[v] < pii.first) continue;
	for(const auto& e: G[v]){
	  if(d[e.to] > d[v] + e.cost){
		d[e.to] = d[v] + e.cost;
		pq.push(MP(d[e.to], e.to));
	  }
	}
  }
}
bool topo_sort(const Graph& G, VI& order){
  order.clear();
  int N = G.size();
  VI color(N, 0);
  
  function<bool(int)> visit = [&](int v)->bool{
	color[v] = 1;
	for(const auto& e: G[v]){
	  if(color[e.to] == 2) continue;
	  if(color[e.to] == 1) return false;
	  if(!visit(e.to)) return false;
	}
	order.push_back(v);
	color[v] = 2;
	return true;
  };

  for(int u=0;u<N;++u)
	if(!color[u] && !visit(u))
	  return false;
  reverse(begin(order), end(order));
  return true;
}


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M, S, T;
  cin >> N >> M >> S >> T;
  --S;
  --T;

  Graph G(N);
  REP(i,M){
	LL u, v, d;
	cin >> u >> v >> d;
	d *= 2;
	--u;
	--v;
	add_edge(G, u, v, d);
  }

  VL dist(N);
  Dijkstra(G, dist, S);
  LL DD = dist[T] / 2;

  Graph D(N), rD(N);
  REP(i,N){
	for(auto& e: G[i]){
	  if(dist[i] + e.cost == dist[e.to]){
		D[i].EB(e.to, e.cost);
		rD[e.to].EB(i, e.cost);
	  }
	}
  }
  VI ord(N);
  topo_sort(D, ord);

  VL num(N);
  num[S] = 1;
  for(int u: ord){
	for(auto& e: D[u]){
	  (num[e.to] += num[u]) %= MOD;
	}
  }

  VL num_r(N);
  num_r[T] = 1;
  for(int i=N-1;i>=0;--i){
	int u = ord[i];
	for(auto& e: rD[u]){
	  (num_r[e.to] += num_r[u]) %= MOD;
	}
  }

  LL ans = num[T] * num[T] % MOD;
  for(int i=0;i<N;++i){
	if(dist[i] == DD){
	  (ans += MOD - num[i]*num[i]%MOD * num_r[i]%MOD*num_r[i] % MOD) %= MOD;
	}
	else if(dist[i] < DD){
	  for(auto& e: D[i]){
		if(DD < dist[e.to]){
		  (ans += MOD - num[i]*num[i]%MOD *num_r[e.to]%MOD*num_r[e.to] % MOD) %= MOD;
		}
	  }
	}
  }

  cout << ans << endl;

  return 0;
}
