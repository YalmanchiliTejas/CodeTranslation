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

vector<int> G[100100];
int p[100100], d[100100];
priority_queue<pair<int, int>> pq;
bool visited[100100];

void dfs(int v=0, int par=-1) {
  p[v] = par;
  if (v) d[v] = d[par] + 1;
  for (int u: G[v]) {
    if (u == par) continue;
    dfs(u, v);
  }
  if (v && G[v].size() == 1) pq.push({d[v], v});
}

void check() {
  while (pq.size()) {
    int v = pq.top().second;
    pq.pop();
    if (visited[v]) continue;
    visited[v] = 1;
    v = p[v];
    if (v == -1 || visited[v]) {
      cout << "First\n";
      exit(0);
    }
    visited[v] = 1;
    v = p[v];
    if (v != -1 && !visited[v]) pq.push({d[v], v});
  }
  cout << "Second\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int n;
  cin >> n;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  if (n & 1) {
    cout << "First\n";
    return 0;
  }
  dfs();
  check();

  




  
  return 0;
}