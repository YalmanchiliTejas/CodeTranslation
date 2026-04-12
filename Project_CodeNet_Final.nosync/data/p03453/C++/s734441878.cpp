#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5;
const long long mod = (long long) 1e9 + 7;
const long long linf = (long long) 1e18;

int n, m;

bool u[N];

long long d1[N];
long long d2[N];

long long dp1[N];
long long dp2[N];

vector< pair<int, int> > g[N];

void dijkstra(int s, long long d[], long long dp[]) {
  for (int i = 0; i < n; i++) {
    d[i] = linf;
  }    
  d[s] = 0;
  dp[s] = 1;
  set< pair<long long, int> > q;
  q.insert(make_pair(d[s], s));
  while (!q.empty()) {
    int v = q.begin()->second; q.erase(q.begin());
    for (auto to: g[v]) {
      if (d[to.first] > d[v] + to.second) {
        q.erase(make_pair(d[to.first], to.first)); 
        q.insert(make_pair(d[to.first] = d[v] + to.second, to.first));
        dp[to.first] = dp[v];
      } else if (d[to.first] == d[v] + to.second) {
        dp[to.first] += dp[v];
        if (dp[to.first] >= mod) {
          dp[to.first] -= mod;
        }
      }
    }
  }  
}

int main() {
  scanf("%d %d", &n, &m);
  int s, t; scanf("%d %d", &s, &t); --s; --t;
  for (int i = 0; i < m; i++) {
    int u, v, d; scanf("%d %d %d", &u, &v, &d); --u; --v;
    g[u].push_back(make_pair(v, d + d));
    g[v].push_back(make_pair(u, d + d));
  }
  dijkstra(s, d1, dp1);
  dijkstra(t, d2, dp2);
  long long ans = dp1[t] * dp2[s] % mod;
  for (int i = 0; i < n; i++) {
    if (d1[i] == d2[i] && d1[i] == d1[t] / 2) {
      ans -= (dp1[i] * dp2[i] % mod) * (dp1[i] * dp2[i] % mod) % mod;
      if (ans < 0) {
        ans += mod;
      }            
    }
  }
  for (int i = 0; i < n; i++) {
    for (auto j: g[i]) {
      if (d1[i] + d2[j.first] + j.second == d1[t] && d1[i] < d1[t] / 2 && d2[j.first] < d2[s] / 2) {
        ans -= (dp1[i] * dp2[j.first] % mod) * (dp1[i] * dp2[j.first] % mod) % mod;
        if (ans < 0) {
          ans += mod;
        }        
      }
    }
  }
  cout << ans;
}
