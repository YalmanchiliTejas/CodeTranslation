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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class S, class T>
ostream& operator<<(ostream& os, pair<S,T>& p){
  return os << p.FF << " " << p.SS;
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
const int INF = 1e6;


struct EdgeEx{
  int to, cap, rev;
  EdgeEx(int to_=0, int cap_ = 0, int rev_ = 0)
	:to(to_), cap(cap_), rev(rev_){}
};

vector< vector<EdgeEx> > GG;
vector<bool> used;
void add_edgeGG(int from, int to, int cap){
  GG[from].push_back(EdgeEx(to, cap, GG[to].size()));
  GG[to].push_back(EdgeEx(from, 0, GG[from].size()-1));
}


// find increase path
int max_flow_dfs(int v, int t, int f){
  if(v == t) return f;
  used[v] = true;
  for(int i=0;i<GG[v].size();++i){
	EdgeEx& e = GG[v][i];
	if(!used[e.to] && e.cap > 0){
	  int d = max_flow_dfs(e.to, t, min(f, e.cap));
	  if(d > 0){
		e.cap -= d;
		GG[e.to][e.rev].cap += d;
		return d;
	  }
	}
  }
  return 0;
}

int max_flow(int s, int t){
  const int V = GG.size();
  int flow = 0;
  used.assign(V, false);
  while(true){
	fill(used.begin(), used.end(), false);
	int f = max_flow_dfs(s, t, INF);
	if(f == 0) return flow;
	flow += f;
  }
}


/////
struct Edge{
  int to, cap, cost, rev;
  Edge(int to_=0, int cap_ = 0, int cost_ = 0, int rev_ = 0)
	:to(to_), cap(cap_), cost(cost_), rev(rev_){}
};

const int MAX_V = 10000;
int V;
vector<Edge> G[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V]; //??´??????????????¨???

void add_edge(int from, int to, int cap, int cost){
  G[from].push_back(Edge(to, cap, cost, G[to].size()));
  G[to].push_back(Edge(from, 0, -cost, G[from].size()-1));
}

int min_cost_flow(int s, int t, int f){
  int res = 0;
  while(f > 0){
	fill(dist, dist+V, INF);
	dist[s] = 0;
	bool update = true;
	while(update){
	  update = false;
	  for(int v=0;v<V;++v){
		if(dist[v] == INF) continue;
		for(int i=0;i<G[v].size();++i){
		  Edge& e = G[v][i];
		  if(e.cap > 0 && dist[v] + e.cost < dist[e.to]){
			dist[e.to] = dist[v] + e.cost;
			prevv[e.to] = v;
			preve[e.to] = i;
			update = true;
		  }
		}
	  }
	}

	if(dist[t] == INF) return -1;

	int d = f;
	for(int v=t;v!=s;v=prevv[v])
	  d = min(d, G[prevv[v]][preve[v]].cap);

	f -= d;
	res += d * dist[t];
	for(int v=t;v!=s;v=prevv[v]){
	  Edge& e = G[prevv[v]][preve[v]];
	  e.cap -= d;
	  G[v][e.rev].cap += d;
	}
  }
  
  return res;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M;
  while(cin>>N>>M,N){
	V = M + N + 2;
	int S = M + N, T = M + N + 1;
	vector<PII> es(M);
	VI deg(N);
	REP(i,M){
	  cin >> es[i];
	  --es[i].FF;
	  --es[i].SS;
	  ++deg[es[i].FF];
	  ++deg[es[i].SS];
	}
	int mx = *max_element(ALL(deg));

	int ans_l = -1, ans_del = 10000;
	int lb = -1, ub = N+1;
	while(ub-lb>1){
	  int m = (lb + ub) / 2;
	  GG.resize(V);
	  REP(i,V) GG[i].clear();
	  REP(i,M){
		add_edgeGG(i, M+es[i].FF, 1);
		add_edgeGG(i, M+es[i].SS, 1);
		add_edgeGG(S, i, 1);
	  }
	  REP(i,N){
		add_edgeGG(M+i, T, m);
	  }

	  int res = max_flow(S, T);
	  if(res != m*N) ub = m;
	  else lb = m;
	}
	ans_l = lb;

	lb = 0, ub = mx-lb+1;

	while(ub - lb > 1){
	  int m = (lb + ub) / 2;
	  REP(i,V) G[i].clear();
	  REP(i,M){
		add_edge(i, M+es[i].FF, 1, 0);
		add_edge(i, M+es[i].SS, 1, 0);
		add_edge(S, i, 1, 0);
	  }
	  REP(i,N){
		add_edge(M+i, T, ans_l, 0);
		if(m)
		  add_edge(M+i, T, m, 1);
	  }
  
	  int res = min_cost_flow(S, T, M);
	  if(res == -1 || M - ans_l*N != res) lb = m;
	  else ub = m;
	}
	ans_del = ub;
	cout << ans_l << " " << ans_l + ans_del << endl;
  }

  return 0;
}