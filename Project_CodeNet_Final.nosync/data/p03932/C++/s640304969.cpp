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

struct Edge{
  int to, cap, cost, rev;
  Edge(int to_=0, int cap_ = 0, int cost_ = 0, int rev_ = 0)
	:to(to_), cap(cap_), cost(cost_), rev(rev_){}
};

const int MAX_V = 200*200*3;
const LL INF = 1e15;
int V;
vector<Edge> G[MAX_V];
LL dist[MAX_V];
int prevv[MAX_V], preve[MAX_V]; //直前の頂点と辺

void add_edge(int from, int to, int cap, int cost){
  G[from].push_back(Edge(to, cap, cost, G[to].size()));
  G[to].push_back(Edge(from, 0, -cost, G[from].size()-1));
}

// 始点s, 終点t, フローf の最小費用流。 存在しなければ-1
int min_cost_flow(int s, int t, int f){
  LL res = 0;
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

  int H, W; cin >> H >> W;
  int WH = W*H;
  REP(y,H) REP(x,W){
	int a; cin >> a;
	int f = y*W+x;
	add_edge(f,f+WH,1,-a);
	add_edge(f,f+WH,100,0);
  }

  REP(y,H-1) REP(x,W){
	add_edge(y*W+x+WH,y*W+x+W,100,0);
  }
  REP(y,H) REP(x,W-1){
	add_edge(y*W+x+WH,y*W+x+1,100,0);
  }

  V = WH+WH;
  cout << -min_cost_flow(0,V-1,2) << endl;
  
  return 0;
}
