#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define N_MAX 21

bool g[N_MAX][N_MAX] = {false};

int main(){

  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u][v] = true;
    g[v][u] = true;
  }

  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }

  int ans = 0;

  do {

    if ( p[0] != 0 ) continue;

    bool ok = true;

    for (int i = 0; i < n - 1; i++) {

      if (!g[p[i]][p[i+1]]) {
	ok = false;
      }
    }

    if ( ok ) {
      ans++;
    }
    
  } while ( next_permutation(p.begin(), p.end()) );
  
  cout << ans << "\n";
  
}