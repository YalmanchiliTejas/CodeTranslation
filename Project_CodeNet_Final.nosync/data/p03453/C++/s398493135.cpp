#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf
#define random_shuffle asdasdd

const int MAXN = 105000;
const long long INF = 1ll * 1e9 * 1e9;
const int mod = (int) 1e9 + 7;

int subMod(int a, int b) {
  int res = a - b;
  return res < 0 ? res + mod : res;
}

struct edge {
  int to, w;
  edge(int to, int w) {
    this->to = to; this->w = w;
  }
};

int n, m;
int s, t;
vector<edge> g[MAXN]; 
long long distS[MAXN], distT[MAXN];
long long waysS[MAXN], waysT[MAXN];
bool used[MAXN];
long long ans;

void dijkstra(int s, long long dist[]) {
  for (int i = 0; i < n; i++) {
    dist[i] = INF;
    used[i] = false;
  }
  dist[s] = 0;
  priority_queue < pair<long long, int> > q;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    long long d = -q.top().first;
    long long idx = q.top().second;
    q.pop();
    if (used[idx]) {
      continue;
    }
    used[idx] = true;
    for (edge e : g[idx]) {
      if (dist[idx] + e.w < dist[e.to]) {
        dist[e.to] = dist[idx] + e.w;
        q.push(make_pair(-dist[e.to], e.to));
      }
    }
  }
}

void countWays(int s, int t, long long distS[], long long distT[], long long waysS[]) {
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  waysS[s] = 1;
  priority_queue < pair<long long, int> > q;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    long long d = -q.top().first;
    long long idx = q.top().second;
    q.pop();
    if (used[idx]) {
      continue;
    }
    used[idx] = true;
    for (edge e : g[idx]) {
      // if (distS[idx] + e.w + distT[e.to] == distS[t]) {
      if (distS[idx] + e.w == distS[e.to]) {
        waysS[e.to] = (waysS[e.to] + waysS[idx]) % mod;
        q.push(make_pair(-distS[e.to], e.to));
      }
    }
  }
}

int main() { 

  scanf("%d %d", &n, &m);
  scanf("%d %d", &s, &t);
  s--; t--;

  for (int i = 0; i < m; i++) {
    int from, to, w;
    scanf("%d %d %d", &from, &to, &w);
    from--; to--;
    g[from].push_back(edge(to, w));
    g[to].push_back(edge(from, w));
  }

  dijkstra(s, distS);
  dijkstra(t, distT);

  countWays(s, t, distS, distT, waysS);
  countWays(t, s, distT, distS, waysT);

  /* for (int i = 0; i < n; i++) {
    cerr << i << " " << distS[i] << " " << distT[i] << endl;
    cerr << i << " " << waysS[i] << " " << waysT[i] << endl;
    cerr << endl;
  } */

  ans = waysS[t] * waysT[s] % mod;
  // cerr << distS[t] << endl;
  // cerr << ans << endl;

  for (int i = 0; i < n; i++) {
    if (distS[i] == distT[i] && distS[i] + distT[i] == distS[t]) {
      long long rem = waysS[i] * waysT[i] % mod;
      rem = rem * rem % mod;
      ans = subMod(ans, rem);
    }
  }

  for (int i = 0; i < n; i++) {
    for (edge e : g[i]) {
      if (distS[i] + e.w + distT[e.to] == distS[t]) {
        if (distT[e.to] > distS[i] - e.w && distT[e.to] < distS[i] + e.w) {
          long long rem = waysS[i] * waysT[e.to] % mod;
          rem = rem * rem % mod;
          // cerr << rem << endl;
          ans = subMod(ans, rem);
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
