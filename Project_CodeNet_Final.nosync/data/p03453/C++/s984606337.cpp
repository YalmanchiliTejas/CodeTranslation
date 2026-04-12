#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
const int mx = 1e5;

int n, m, s, t;
vector<pair<int, ll>> G[100100];

ll d[2][100100];
ll dp[2][100100];

void dijkstra() {
  rep(i, 2) rep(j, n) d[i][j] = INF;
  d[0][s] = 0, d[1][t] = 0;
  dp[0][s] = 1, dp[1][t] = 1;
  priority_queue<pair<ll, int>> pq;
  pq.push({0, s});
  pq.push({0, t + mx});
  while (pq.size()) {
    pair<ll, int> p = pq.top();
    pq.pop();
    int v = p.second % mx, id = p.second / mx;
    if (d[id][v] != -p.first) continue;
    for (auto e: G[v]) {
      int u = e.first;
      ll c = e.second;
      if (chmin(d[id][u], d[id][v] + c)) {
        dp[id][u] = 0;
        pq.push({-d[id][u], id * mx + u});
      }
      if (d[id][u] == d[id][v] + c) dp[id][u] = (dp[id][u] + dp[id][v]) % mod;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  cin >> n >> m >> s >> t;
  s--, t--;
  rep(i, m) {
    int u, v;
    ll x;
    cin >> u >> v >> x;
    u--, v--;
    G[u].push_back({v, x});
    G[v].push_back({u, x});
  }

  dijkstra();
  ll ans = dp[0][t] * dp[0][t] % mod;
  rep(i, n) if (d[0][i] + d[1][i] == d[0][t]) {
    if (d[0][i] == d[1][i]) {
      ans += mod - dp[0][i] * dp[0][i] % mod * dp[1][i] % mod * dp[1][i] % mod;
      ans %= mod;
    }
    else if (d[0][i] < d[1][i]) {
      for (auto e: G[i]) {
        int j = e.first;
        ll c = e.second;
        if (d[0][j] + d[1][j] == d[0][t] && d[0][j] > d[1][j] && d[0][j] == d[0][i] + c) {
          ans += mod - dp[0][i] * dp[0][i] % mod * dp[1][j] % mod * dp[1][j] % mod;
          ans %= mod;
        }
      }
    }
  }
  cout << ans << '\n';


  




  
  return 0;
}