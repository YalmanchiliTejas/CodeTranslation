#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

typedef pair<int, int> Pi;
typedef tuple<int, int, int> Ti;
typedef vector<int> vint;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

struct edge {
  int to, cap, rev;
  edge(){}
  edge(int to, int cap, int rev):to(to), cap(cap), rev(rev){}
};

struct Dinic {
  vector< vector<edge> > G;
  vector<int> level, iter;
  Dinic(int V):G(V), level(V), iter(V){}
  int add_edge(int from, int to, int cap) {
    G[from].emplace_back(to, cap, G[to].size());
    G[to].emplace_back(from, 0, G[from].size()-1);
    return G[from].size()-1;
  }
  bool bfs(int s, int t) {
    fill(all(level), -1);
    queue<int> que;
    que.push(s);
    level[s] = 0;
    while(!que.empty()) {
      int v = que.front(); que.pop();
      rep(i, G[v].size()) {
	edge& e = G[v][i];
	if(e.cap > 0 && level[e.to] < 0) {
	  level[e.to] = level[v] + 1;
	  que.push(e.to);
	}
      }
    }
    return level[t] >= 0;
  }
  int dfs(int v, int t, int f) {
    if(v == t) return f;
    for(int& i = iter[v]; i < (int)G[v].size(); i++) {
      edge& e = G[v][i];
      if(e.cap > 0 && level[v] < level[e.to]) {
	int d = dfs(e.to, t, min(f, e.cap));
	if(d > 0) {
	  e.cap -= d;
	  G[e.to][e.rev].cap += d;
	  return d;
	}
      }
    }
    return 0;
  }
  int max_flow(int s, int t, int mf = inf) {
    int flow = 0;
    while(bfs(s, t)) {
      fill(all(iter), 0);
      int f; while((f = dfs(s, t, mf)) > 0) flow += f;
    }
    return flow;
  }
};

int n, m;
vector<Pi> E;

bool solve(int l, int h) {
  int S = n+m, T = S+1, V = T+1;
  int D = T+1;
  Dinic G(V +1);
  rep(i, m) {
    int u, v;
    tie(u, v) = E[i];
    G.add_edge(S, i, 1);
    G.add_edge(i, m+u, 1);
    G.add_edge(i, m+v, 1);
  }
  vector<int> idx(n);
  rep(i, n) {
    idx[i] = G.add_edge(m+i, T, h);
  }
  int mxf = G.max_flow(S, T);
  if(mxf != m) return false;
  //cout<<mxf<<endl;
  /*
  rep(i, n) {
    edge& e = G.G[m+i][idx[i]];
    int cap = G.G[e.to][e.rev].cap;
    //cout<<e.cap << " "<<cap<<endl;
    //cout<<cap<<" "<<l<<" "<<h<<endl;
    if(cap < l || cap > h) return false;
  }
  */
  rep(i, n) {
    G.add_edge(m+i, D, l);
  }
  mxf = G.max_flow(T, D);
  if(mxf != l*n) return false;
  return true;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  while(cin >> n >> m, n || m) {
    E.clear();
    rep(i, m) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      E.emplace_back(u, v);
    }

    int ansl = 0, ansh = m;
    /**/
    int lh = 0, uh = m*2;
    while(lh+1 < uh) {
      int mh = (lh+uh)/2;
      int ll = 0, ul = mh+1;
      while(ll+1 < ul) {
	int ml = (ll+ul)/2;
	if(solve(ml, mh)) ll = ml;
	else ul = ml;
      }
      if(solve(ll, mh)) {
	uh = mh;
	if(ansh-ansl > mh-ll) ansl = ll, ansh = mh;
      } else lh = mh;
    }
    /*
    int l = 0, h = 0;
    for(;;) {
      while(h <= m && !solve(l, h)) h++;
      if(!solve(l, h)) break;
      if(ansh-ansl > h-l) ansl = l, ansh = h;
      l++;
    }
    */
    cout << ansl << " " << ansh << endl;
  }

  return 0;
}