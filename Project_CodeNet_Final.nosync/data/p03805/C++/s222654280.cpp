#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )

int N, M;
vector<vector<int> > G;

int dfs(int v, int bit) {
  if ( bit == (1<<N)-1 ) return 1;
  int ret = 0;
  for ( int &u: G[v] ) {
    if ( (1<<u) & bit ) continue;
    ret += dfs(u, bit|(1<<u));
  }

  return ret;
}
 
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> M;
  G.resize(N);
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  cout << dfs(0, 1) << endl;

  return 0;
}
