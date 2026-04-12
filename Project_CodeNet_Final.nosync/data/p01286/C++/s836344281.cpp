#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

struct Dinic {
  struct edge {
    int to, cap, rev;
    edge(){}
    edge(int to, int cap, int rev):to(to), cap(cap), rev(rev){}
  };
  vector< vector<edge> > graph;
  vector<int> level, iter;
  Dinic(){}
  Dinic(int V):graph(V), level(V), iter(V){}
  void add_edge(int from, int to, int cap) {
    graph[from].emplace_back(to, cap, graph[to].size());
    graph[to].emplace_back(from, 0, graph[from].size()-1);
  }
  void bfs(int s) {
    fill(all(level), -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()) {
      int v = que.front(); que.pop();
      for(edge& e : graph[v]) {
	if(e.cap > 0 && level[e.to] < 0) {
	  level[e.to] = level[v] + 1;
	  que.push(e.to);
	}
      }
    }
  }
  int dfs(int v, int t, int f) {
    if(v == t) return f;
    for(int& i = iter[v]; i < graph[v].size(); i++) {
      edge& e = graph[v][i];
      if(e.cap > 0 && level[v] < level[e.to]) {
	int d = dfs(e.to, t, min(f, e.cap));
	if(d > 0) {
	  e.cap -= d;
	  graph[e.to][e.rev].cap += d;
	  return d;
	}
      }
    }
    return 0;
  }
  int max_flow(int s, int t) {
    int flow = 0;
    while(1) {
      bfs(s);
      if(level[t] < 0) return flow;
      fill(all(iter), 0);
      int f; while((f = dfs(s, t, inf)) > 0) flow += f;
    }
  }
};

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int H, W, C, M, Nw, Nc, Nm;
  while(cin >> H >> W >> C >> M >> Nw >> Nc >> Nm, ~H) {
    int V = 0, S, T;
    vector<int> hi, ho, wi, wo, ci, co, mi, mo;
    int dwi, dwo, dci, dco, dmi, dmo;
    rep(i, H) hi.push_back(V++), ho.push_back(V++);
    rep(i, W) wi.push_back(V++), wo.push_back(V++);
    rep(i, C) ci.push_back(V++), co.push_back(V++);
    rep(i, M) mi.push_back(V++), mo.push_back(V++);
    dwi = V++, dwo = V++;
    dci = V++, dco = V++;
    dmi = V++, dmo = V++;
    S = V++, T = V++;
    Dinic graph(V);
    rep(i, H) {
      graph.add_edge(S, hi[i], 1);
      graph.add_edge(hi[i], ho[i], 1);
      graph.add_edge(ho[i], dwi, 1);
    }
    rep(i, W) {
      int n; cin >> n;
      rep(j, n) {
	int h; cin >> h;
	graph.add_edge(ho[--h], wi[i], 1);
      }
      graph.add_edge(wi[i], wo[i], 1);
      graph.add_edge(wo[i], dci, 1);
    }
    graph.add_edge(dwi, dwo, Nw);
    rep(i, C) {
      graph.add_edge(dwo, ci[i], 1);
      int n; cin >> n;
      rep(j, n) {
	int w; cin >> w;
	graph.add_edge(wo[--w], ci[i], 1);
      }
      graph.add_edge(ci[i], co[i], 1);
      graph.add_edge(co[i], dmi, 1);
    }
    graph.add_edge(dci, dco, Nc);
    rep(i, M) {
      graph.add_edge(dco, mi[i], 1);
      int n; cin >> n;
      rep(j, n) {
	int c; cin >> c;
	graph.add_edge(co[--c], mi[i], 1);
      }
      graph.add_edge(mi[i], mo[i], 1);
      graph.add_edge(mo[i], T, 1);
    }
    graph.add_edge(dmi, dmo, Nm);
    graph.add_edge(dmo, T, Nm);
    cout << graph.max_flow(S, T) << endl;
  }

  return 0;
}