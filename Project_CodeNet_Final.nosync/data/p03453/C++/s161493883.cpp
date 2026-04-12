#define _USE_MATH_DEFINES
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int64, int64> ii;
const int64 INF = 1LL << 60;
const int MOD = 1e9 + 7;

const int N = 1e5 + 10;
vector<ii> a[N];
int64 d[N], e[N];
int dp[N], ep[N];

void dijkstra(int s, int n, int64 d[], int dp[]) {
  fill(d, d + n, INF);
  d[s] = 0;
  dp[s] = 1;
  priority_queue<ii, vector<ii>, greater<ii>> Q;
  Q.push({d[s], s});
  while (!Q.empty()) {
    ii top = Q.top();
    Q.pop();
    int64 u = top.second, dd = top.first;
    if (dd != d[u]) continue;
    for (auto& it : a[u]) {
      int64 v = it.first, cost = it.second;
      if (d[v] > d[u] + cost) {
        d[v] = d[u] + cost;
        dp[v] = dp[u];
        Q.push({d[v], v});
      } else if (d[v] == d[u] + cost) {
        dp[v] = (dp[v] + dp[u]) % MOD;
      }
    }
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int s, t;
  scanf("%d%d", &s, &t);
  --s; --t;
  while (m--) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    --x; --y;
    a[x].push_back({y, z});
    a[y].push_back({x, z});
  }
  dijkstra(s, n, d, dp);
  dijkstra(t, n, e, ep);
  int64 dist = d[t];
  // trace(dist);
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    if (d[i] == INF) continue;
    if (d[i] * 2 == dist) {
      int cur = (int64)dp[i] * ep[i] % MOD;
      // trace(i, cur);
      ret = (ret + (int64)cur * cur) % MOD;
    }
    for (auto& it : a[i]) {
      int j = it.first, cost = it.second;
      if (d[i] + cost + e[j] == dist &&
          d[i] * 2 < dist && d[j] * 2 > dist) {
        int cur = (int64)dp[i] * ep[j] % MOD;
        // trace(i, j, cur);
        ret = (ret + (int64)cur * cur) % MOD;
      }
    }
  }
  ret = ((int64)dp[t] * dp[t] % MOD + MOD - ret) % MOD;
  printf("%d\n", ret);
  return 0;
}
