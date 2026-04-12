#include <bits/stdc++.h>
using namespace std;

#define int long long

int N, M;
bool G[8][8] = {{}};

int dfs(int b, int v) {
  if ( b == (1<<N)-1 ) return 1;

  int ret = 0;
  for ( int i = 0; i < N; i++ ) {
    if ( b&(1<<i) ) continue;
    if ( G[v][i] ) ret += dfs(b|(1<<i), i);
  }

  return ret;
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N >> M;

  for ( int i = 0; i < M; i++ ) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a][b] = true;
    G[b][a] = true;
  }  

  cout << dfs(1, 0) << endl;
  
  return 0;
}
