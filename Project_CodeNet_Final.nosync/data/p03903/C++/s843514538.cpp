#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> P2;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int N, M, Q;
int U[4000], R[4000];
int find(int x) {
  if (U[x] == x) return x;
  return U[x] = find(U[x]);
}
void unite(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (R[x] < R[y]) swap(x, y);
  U[y] = x;
  R[x] += R[y];
}
bool same(int x, int y) {
  return find(x) == find(y);
}

vector<P> G[4000];
int par[4000], dep[4000];
int pare[4000];
void dfs(int x, int p, int r, int pe) {
  par[x] = p;
  pare[x] = pe;
  dep[x] = r;
  for (P pp : G[x]) if (pp._1 != p) dfs(pp._1, x, r+1, pp._2);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N >> M;
  vector<P2> edges;
  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    edges.pb(P2(c, P(a, b)));
  }
  rep(i, N) U[i] = i, R[i] = 1;
  sort(all(edges));
  long long sum = 0;
  for (P2 p : edges) {
    int c = p._1, a = p._2._1, b = p._2._2;
    if (!same(a, b)) {
      G[a].pb(P(b, c));
      G[b].pb(P(a, c));
      unite(a, b);
      sum += c;
    }
  }
  dfs(0, -1, 0, 0);
  cin >> Q;
  rep(i, Q) {
    int s, t;
    cin >> s >> t;
    s--, t--;
    int m = 0;
    if (dep[s] < dep[t]) swap(s, t);
    while (dep[s] > dep[t]) {
      m = max(m, pare[s]), s = par[s];
    }
    while (s != t) {
      m = max(m, pare[s]), s = par[s];
      m = max(m, pare[t]), t = par[t];
    }
    cout << sum-m << "\n";
  }
  return 0;
}
