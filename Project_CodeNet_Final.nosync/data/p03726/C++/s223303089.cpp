#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const ld eps = 1e-9;
const ll MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

struct HopcroftKarp {
    vector< vector< int > > graph;
    vector< int > dist, match;
    vector< bool > used, vv;

    HopcroftKarp(int n, int m) : graph(n), match(m, -1), used(n) {}

    void add_edge(int u, int v) {
      graph[u].push_back(v);
    }

    void bfs() {
      dist.assign(graph.size(), -1);
      queue< int > que;
      for(int i = 0; i < graph.size(); i++) {
        if(!used[i]) {
          que.emplace(i);
          dist[i] = 0;
        }
      }

      while(!que.empty()) {
        int a = que.front();
        que.pop();
        for(auto &b : graph[a]) {
          int c = match[b];
          if(c >= 0 && dist[c] == -1) {
            dist[c] = dist[a] + 1;
            que.emplace(c);
          }
        }
      }
    }

    bool dfs(int a) {
      vv[a] = true;
      for(auto &b : graph[a]) {
        int c = match[b];
        if(c < 0 || (!vv[c] && dist[c] == dist[a] + 1 && dfs(c))) {
          match[b] = a;
          used[a] = true;
          return (true);
        }
      }
      return (false);
    }

    int bipartite_matching() {
      int ret = 0;
      while(true) {
        bfs();
        vv.assign(graph.size(), false);
        int flow = 0;
        for(int i = 0; i < graph.size(); i++) {
          if(!used[i] && dfs(i)) ++flow;
        }
        if(flow == 0) return (ret);
        ret += flow;
      }
    }

    void output() {
      for(int i = 0; i < match.size(); i++) {
        if(~match[i]) {
          cout << match[i] << "-" << i << endl;
        }
      }
    }
};


int id1 = 0, id2 = 0;
vi v;

void dfs(int now, int prev, bool parity, const vvi &tr) {
  if(!parity) {
    v[now] = id1;
    id1++;
  } else {
    v[now] = id2;
    id2++;
  };

  for(int k=0;k<SZ(tr[now]);++k) {
    int nxt = tr[now][k];
    if(nxt == prev)continue;
    dfs(nxt, now, !parity, tr);
  }
}

void dfs2(int now, int prev, bool parity, const vvi &tr, HopcroftKarp &match) {
  for(int i=0;i<SZ(tr[now]);++i) {
    int nxt = tr[now][i];
    if(nxt == prev) continue;
    if(!parity) {
      match.add_edge(v[now], v[nxt]);
    } else {
      match.add_edge(v[nxt], v[now]);
    }
    dfs2(nxt, now, !parity, tr, match);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n; cin >> n;
  vvi tr(n);
  for(int i=0;i<n-1;++i) {
    int a, b; cin >> a >> b;
    a--; b--;
    tr[a].push_back(b);
    tr[b].push_back(a);
  }

  v.resize(n);
  dfs(0, -1, 0, tr);
  HopcroftKarp match(id1, id2);
  id1 = 0, id2 = 0;
  dfs2(0, -1, 0, tr, match);

  int bm = match.bipartite_matching();
  //cout << bm << endl;

  if(n % 2 == 0 && bm == n/2) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }
}
