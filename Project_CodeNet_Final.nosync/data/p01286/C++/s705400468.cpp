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
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
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
const int INF = 1e9;

struct EdgeEx{
  int to, cap, rev;
  EdgeEx(int to_=0, int cap_ = 0, int rev_ = 0)
	:to(to_), cap(cap_), rev(rev_){}
};


vector< vector<EdgeEx> > G;
void add_edge(int from, int to, int cap){
  G[from].push_back(EdgeEx(to, cap, G[to].size()));
  G[to].push_back(EdgeEx(from, 0, G[from].size()-1));
}

int max_flow_dfs(int u, int t, int f, vector<bool>& finished, vector<int>& level){
  if (u == t || f == 0) return f;
  if (finished[u]) return 0;
  finished[u] = true;
  for(auto& e: G[u]){
	if(level[e.to] > level[u]){
	  int fp = max_flow_dfs(e.to, t, min(f, e.cap), finished, level);
	  if(fp > 0) {
		e.cap -= fp;
		G[e.to][e.rev].cap += fp;
		finished[u] = false;
		return fp;
	  }
    }
  }
  return 0;
}
int maximumFlow(int s, int t) {
  int N = G.size();
  int total = 0;
  for(bool up=true;up;){
	up = false;
    vector<int> level(N, -1); level[s] = 0;
    queue<int> Q; Q.push(s);
    for(int d = N; !Q.empty() && level[Q.front()] < d; ) {
      int u = Q.front(); Q.pop();
      if (u == t) d = level[u];
      for(auto& e: G[u])
		if (e.cap > 0 && level[e.to] == -1)
		  Q.push(e.to), level[e.to] = level[u] + 1;
    }
    vector<bool> finished(N);
    for(int f = 1; f > 0; ) {
      f = max_flow_dfs(s, t, INF, finished, level);
      if (f == 0) break;
      total += f; up = true;
    }
  }
  return total;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int H,W,C,M,NW,NC,NM;
  while(cin>>H>>W>>C>>M>>NW>>NC>>NM,H>=0){
	int sum = H+W+C+M;
	int S = sum*2+7, T = 0;
	G.assign(S+1, vector<EdgeEx>());
	FOR(i,1,W+1){
	  int n; cin >> n;
	  REP(j,n){
		int x; cin >> x;
		add_edge(H+i,sum+x, 1);
	  }
	}
	FOR(i,1,C+1){
	  int n; cin >> n;
	  REP(j,n){
		int x; cin >> x;
		add_edge(H+W+i, sum+H+x, 1);
	  }
	}
	FOR(i,1,M+1){
	  int n; cin >> n;
	  REP(j,n){
		int x; cin >> x;
		add_edge(H+W+C+i, sum+H+W+x, 1);
	  }
	}
	FOR(i,1,H+1) add_edge(i, T, 1);
	FOR(i,1,M+1) add_edge(S, sum+H+W+C+i, 1);
	
	FOR(i,1,H+1) add_edge(sum*2+1, sum+i, 1);
	FOR(i,1,C+1) add_edge(H+W+i, sum*2+2, 1);
	add_edge(sum*2+2, sum*2+1, NW);

	FOR(i,1,W+1) add_edge(sum*2+3, sum+H+i, 1);
	FOR(i,1,M+1) add_edge(H+W+C+i, sum*2+4, 1);
	add_edge(sum*2+4, sum*2+3, NC);

	FOR(i,1,C+1) add_edge(sum*2+5, sum+H+W+i, 1);
	add_edge(S, sum*2+5, NM);
	FOR(i,1,sum+1) add_edge(sum+i, i, 1);

	cout << maximumFlow(S,T) << endl;
  }
  
  return 0;
}