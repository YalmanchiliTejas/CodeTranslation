#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5;

ll dist[2][N];
ll dp[2][N];
int n, m;
using P = tuple<ll, int>;
vector<P> treeone[N]; // not tree, graph
constexpr int mod = 1e9 + 7;

void dijkstra(int s, int x) {
  for(int i = 0; i < n; i++) dist[x][i] = 1e18;
  priority_queue<P, vector<P>, greater<P> > pq;
  pq.emplace(0, s);
  dist[x][s] = 0;
  dp[x][s] = 1;
  while(pq.size()) {
    ll d = get<0>(pq.top()); int i = get<1>(pq.top());
    pq.pop();
    if(dist[x][i] < d) continue;
    for(auto to : treeone[i]) {
      int j = get<0>(to), co = get<1>(to);
      if(dist[x][j] > d + co) {
        dp[x][j] = dp[x][i];
        dist[x][j] = d + co;
        pq.emplace(d + co, j);
      } else if(dist[x][j] == d + co) {
        (dp[x][j] += dp[x][i]) %= mod;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> m;
  int s, t; cin >> s >> t; s--; t--;
  for(int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    treeone[a].emplace_back(b, c);
    treeone[b].emplace_back(a, c);
  }
  dijkstra(s, 0);
  dijkstra(t, 1);
  ll ans = dp[0][t] * dp[1][s] % mod;
  for(int i = 0; i < n; i++) {
    if(2 * dist[0][i] == dist[0][t]) {
      ans -= dp[0][i] * dp[1][i] % mod * dp[0][i] % mod * dp[1][i] % mod;
    }
    for(auto to : treeone[i]) {
      int j = get<0>(to), w = get<1>(to);
      if(dist[0][i] + dist[1][j] + w == dist[0][t] &&
          2 * dist[0][i] < dist[0][t] && dist[0][t] < 2 * dist[0][i] + 2ll * w) {
        ans -= dp[0][i] * dp[1][j] % mod * dp[0][i] % mod * dp[1][j] % mod;
      }
    }
  }
  ans = (ans % mod + mod) % mod;
  cout << ans << endl;
}

