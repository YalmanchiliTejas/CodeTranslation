#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;
const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
template <typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
  if(a < b) {a = b; return true;}
  return false;
}
template <typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
  if(a > b) {a = b; return true;}
  return false;
}
template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}
template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for(int i=0;i<((int)(v.size()));++i) {
    if(i) os << " ";
    os << v[i];
  }
  return os;
}
template <typename T>
struct Dinic {
  int sz;
  T inf = numeric_limits<T>::max();
  vector<int> level, iter;
  struct Edge {
    int to, rev;
    T cap;
    Edge(int to, int rev, T cap): to(to), rev(rev), cap(cap) {}
  };
  vector<vector<Edge>> g;
  Dinic(int V): sz(V) {
    g.resize(V);
    level.resize(V);
    iter.resize(V);
  };
  void add_edge(int from, int to, T cap) {
    g[from].emplace_back(to, (int)(g[to].size()), cap);
    g[to].emplace_back(from, (int)(g[from].size())-1, 0);
  }
  T max_flow(int s, int t) {
    T flow = 0;
    while(1) {
      bfs(s);
      if(level[t] < 0) return flow;
      iter.assign(sz, 0);
      T f = dfs(s, t, inf);
      while(f > 0) {
        flow += f;
        f = dfs(s, t, inf);
      }
    }
  }
private:
  void bfs(int s) {
    level.assign(sz, -1);
    level[s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()) {
      int now = que.front(); que.pop();
      for(auto &e: g[now]) {
        if(e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[now] + 1;
          que.push(e.to);
        }
      }
    }
  }
  T dfs(int s, int t, T flow) {
    if(s == t) return flow;
    for(int i=iter[s];i<(int)(g[s].size());++i) {
      iter[s] = i;
      auto e = g[s][i];
      if(e.cap > 0 && level[s] < level[e.to]) {
        T d = dfs(e.to, t, min(flow, e.cap));
        if(d > 0) {
          g[s][i].cap -= d;
          g[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
};
int cnt = 0;
bool solve() {
  cnt++;
  int h, w, c, m, nw, nc, nm; cin >> h >> w >> c >> m >> nw >> nc >> nm;
  if(h < 0) return false;
  int k = 2*h + 2*w + 2*c + 2*m;
  Dinic<int> flow(k + 8);
  for(int i=0;i<(h);++i) {
    flow.add_edge(i+1, i+h+1, 1);
  }
  for(int i=0;i<(w);++i) {
    flow.add_edge(i+2*h+1, i+2*h+w+1, 1);
  }
  for(int i=0;i<(c);++i) {
    flow.add_edge(i+2*h+2*w+1, i+2*h+2*w+c+1, 1);
  }
  for(int i=0;i<(m);++i) {
    flow.add_edge(i+2*h+2*w+2*c+1, i+2*h+2*w+2*c+m+1, 1);
  }
  for(int i=0;i<(h);++i) {
    flow.add_edge(0, i+1, 1);
  }
  for(int i=0;i<(w);++i) {
    int t; cin >> t;
    set<int> st;
    for(int j=0;j<(t);++j) {
      int hj;
      cin >> hj;
      hj--;
      st.insert(hj);
    }
    for(auto hj: st) {
      flow.add_edge(hj+h+1, i+2*h+1, 1);
    }
  }
  for(int i=0;i<(c);++i) {
    int t; cin >> t;
    set<int> st;
    for(int j=0;j<(t);++j) {
      int cj;
      cin >> cj;
      cj--;
      st.insert(cj);
    }
    for(auto &cj: st) {
      flow.add_edge(cj+2*h+w+1, i+2*h+2*w+1, 1);
    }
  }
  for(int i=0;i<(m);++i) {
    int t; cin >> t;
    set<int> st;
    for(int j=0;j<(t);++j) {
      int mj;
      cin >> mj;
      mj--;
      st.insert(mj);
    }
    for(auto &mj: st) {
      flow.add_edge(mj+2*h+2*w+c+1, i+2*h+2*w+2*c+1, 1);
    }
  }
  for(int i=0;i<(m);++i) {
    flow.add_edge(i+2*h+2*w+2*c+m+1, k+7, 1);
  }
  flow.add_edge(k+1, k+2, nw);
  for(int i=0;i<(h);++i) {
    flow.add_edge(i+1, k+1, 1);
  }
  for(int i=0;i<(c);++i) {
    flow.add_edge(k+2, i+2*h+2*w+1, 1);
  }
  flow.add_edge(k+3, k+4, nc);
  for(int i=0;i<(w);++i) {
    flow.add_edge(i+2*h+w+1, k+3, 1);
  }
  for(int i=0;i<(m);++i) {
    flow.add_edge(k+4, i+2*h+2*w+2*c+1, 1);
  }
  flow.add_edge(k+5, k+6, nm);
  for(int i=0;i<(c);++i) {
    flow.add_edge(i+2*h+2*w+c+1, k+5, 1);
  }
  flow.add_edge(k+6, k+7, INF);
  cout << flow.max_flow(0, k+7) << endl;
  return true;
}
int main() {
  cout << fixed << setprecision(10);
  while(solve()) {}
}

