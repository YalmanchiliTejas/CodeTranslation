#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define RFOR(i, a, b) for(int i=(a); i>=(b); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, n, 0)
#define CEIL(n, m) ceil(n/pow(10.0, m))*pow(10.0, m)
#define FLOOR(n, m) floor(n/pow(10.0, m))*pow(10.0, m)
#define ROUND(n, m) round(n/pow(10.0, m))*pow(10.0, m)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort((x).begin(),(x).end())
#define RSORT(x) sort((x).begin(),(x).end(),greater<int>())
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define llong long long
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) " (L" << __LINE__ << ") " << __FILE__ << endl;

const int nmax = 8;
vector<vector<int>> graph(nmax, vector<int>(nmax, 0));

int dfs(int v, int N, vector<bool> visited) {
  bool all_visited=true;

  for (int i=0; i<N; i++) {
    if (visited[i] == false) all_visited=false;
  }
  if (all_visited) return 1;

  int ret=0;
  for (int i=0; i<N; i++) {
    if (graph[v][i] == false) continue;
    if (visited[i]) continue;

    visited[i] = true;
    ret += dfs(i, N, visited);
    visited[i] = false;
  }
  return ret;
}

void solve()
{
  int ans=0;

  int n; cin >> n;
  int m; cin >> m;

  for (int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a-1][b-1] = 1;
    graph[b-1][a-1] = 1;
  }

  vector<bool> visited(nmax, false);
  visited[0] = true;
  ans = dfs(0, n, visited);

  cout << ans << endl;
}

int main()
{
  solve();
  return 0;
}
