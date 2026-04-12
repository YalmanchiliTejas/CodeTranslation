#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/// --- MinCostFlow Library {{{ ///
struct MinCostFlow {
  struct Edge {
    int to; ll cap, cost; size_t rev;
  };
  int n;
  vector< vector<Edge> > graph;
  vector<ll> dist;
  vector<int> prevv, previ;
  ll inf;
  MinCostFlow(int n, ll inf): n(n), graph(n), dist(n), prevv(n), previ(n), inf(inf) {}
  void addEdge(int a, int b, ll cap, ll cost, int undirected = 0) {
    graph[a].emplace_back((Edge) {b, cap, cost, graph[b].size()});
    graph[b].emplace_back((Edge) {a, undirected ? cap : 0, -cost, graph[a].size() - 1});
  }
  ll solve(int s, int t, ll f) {
    ll res = 0;
    while(f > 0) {
      fill(begin(dist), end(dist), inf);
      dist[s] = 0;
      bool update = 1;
      // Bellman-Ford
      while(update) {
        update = 0;
        for(int v = 0; v < n; v++) {
          if(dist[v] == inf) continue;
          for(size_t i = 0; i < graph[v].size(); i++) {
            Edge &edge = graph[v][i];
            if(edge.cap > 0 && dist[edge.to] > dist[v] + edge.cost) {
              dist[edge.to] = dist[v] + edge.cost;
              prevv[edge.to] = v;
              previ[edge.to] = i;
              update = 1;
            }
          }
        }
      }
      //
      if(dist[t] == inf) return -1;
      ll d = f;
      for(int v = t; v != s; v = prevv[v]) {
        d = min(d, graph[prevv[v]][previ[v]].cap);
      }
      f -= d;
      res += d * dist[t];
      for(int v = t; v != s; v = prevv[v]) {
        Edge &edge = graph[prevv[v]][previ[v]];
        edge.cap -= d;
        graph[v][edge.rev].cap += d;
      }
    }
    return res;
  }
};

/// }}}--- ///

const int N = 200 * 200;
ll inf = 1e18;
MinCostFlow ecas(N * 2, inf);

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int a[200][200];
  int h, w; cin >> h >> w;
  int s = 0 + N, t = w * h - 1;
  // ある最適解を, 二人が交わらないようにすることが可能.
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
    cin >> a[i][j];
    a[i][j] = - a[i][j];
    ecas.addEdge(i * w + j, i * w + j + N, 1, a[i][j]);
  }
  for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
    if(i != h - 1) ecas.addEdge(i * w + j + N, (i + 1) * w + j, 1, 0);
    if(j != w - 1) ecas.addEdge(i * w + j + N, i * w + (j + 1), 1, 0);
  }
  ll ans = a[0][0] + a[h - 1][w - 1];
  ans += ecas.solve(s, t, 2);
  cout << -ans << endl;
}

