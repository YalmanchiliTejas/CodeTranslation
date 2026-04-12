#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

const int MAX_V = 1000;
const int INF = 1e9;

struct Edge {int to, cap, rev;};

struct MaxFlow {
  int v;
  vector<Edge> G[MAX_V];
  int level[MAX_V];
  int iter[MAX_V];

  MaxFlow() {v = 0;}

  int next() {return v++;}
  
  void add_edge(int from, int to, int cap) {
    G[from].push_back((Edge){to, cap, int(G[to].size())});
    G[to].push_back((Edge){from, 0, int(G[from].size()) - 1});
  }

  void bfs(int s) {
    memset(level, -1, sizeof(level));
    level[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      rep (i, G[v].size()) {
	Edge &e = G[v][i];
	if (e.cap == 0 || level[e.to] >= 0) continue;
	level[e.to] = level[v] + 1;
	que.push(e.to);
      }
    }
  }

  int dfs(int v, int t , int f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < int(G[v].size()); ++i) {
      Edge &e = G[v][i];
      if (e.cap == 0 || level[v] >= level[e.to]) continue;
      int d = dfs(e.to, t, min(f, e.cap));
      if (d == 0) continue;
      e.cap -= d;
      G[e.to][e.rev].cap += d;
      return d;
    }
    return 0;
  }

  int max_flow (int s, int t) {
    int flow = 0, f;
    while (true) {
      bfs(s);
      if (level[t] < 0) return flow;
      memset(iter, 0, sizeof(iter));
      while ((f = dfs(s, t, INF)) > 0) flow += f;
    }
  }
};

int main() {
  while (true) {
    int h, w, c, m, nw, nc, nm;
    cin >> h >> w >> c >> m >> nw >> nc >> nm;
    if (h < 0) break;
    MaxFlow mf;
    int from = mf.next();
    int to = mf.next();
    int wai = mf.next();
    int wao = mf.next();
    int cai = mf.next();
    int cao = mf.next();
    int mai = mf.next();
    int mao = mf.next();
    int hi[h], ho[h], wi[w], wo[w], ci[c], co[c], mi[m], mo[m];
    rep (i, h) hi[i] = mf.next();
    rep (i, h) ho[i] = mf.next();
    rep (i, w) wi[i] = mf.next();
    rep (i, w) wo[i] = mf.next();
    rep (i, c) ci[i] = mf.next();
    rep (i, c) co[i] = mf.next();
    rep (i, m) mi[i] = mf.next();
    rep (i, m) mo[i] = mf.next();
    rep (i, h) mf.add_edge(from, hi[i], 1);
    rep (i, h) mf.add_edge(hi[i], ho[i], 1);
    rep (i, w) mf.add_edge(wi[i], wo[i], 1);
    rep (i, c) mf.add_edge(ci[i], co[i], 1);
    rep (i, m) mf.add_edge(mi[i], mo[i], 1);
    rep (i, m) mf.add_edge(mo[i], to, 1);
    rep (i, w) {
      int k;
      cin >> k;
      rep (j, k) {
	int a;
	cin >> a;
	--a;
	mf.add_edge(ho[a], wi[i], 1);
      }
    }
    rep (i, c) {
      int k;
      cin >> k;
      rep (j, k) {
	int a;
	cin >> a;
	--a;
	mf.add_edge(wo[a], ci[i], 1);
      }
    }
    rep (i, m) {
      int k;
      cin >> k;
      rep (j, k) {
	int a;
	cin >> a;
	--a;
	mf.add_edge(co[a], mi[i], 1);
      }
    }
    mf.add_edge(wai, wao, nw);
    mf.add_edge(cai, cao, nc);
    mf.add_edge(mai, mao, nm);
    mf.add_edge(mao, to, 1000);
    rep (i, h) mf.add_edge(ho[i], wai, 1);
    rep (i, w) mf.add_edge(wo[i], cai, 1);
    rep (i, c) mf.add_edge(co[i], mai, 1);
    rep (i, c) mf.add_edge(wao, ci[i], 1);
    rep (i, m) mf.add_edge(cao, mi[i], 1);
    cout << mf.max_flow(from, to) << endl;
  }
  return 0;
}