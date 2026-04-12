#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 階乗
ll factorial(int n) {
  if(n == 0) return 1;
  return n * factorial(n - 1);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  // 無向(有向)グラフの隣接行列
  int n, m, u, v;
  cin >> n >> m;
  
  int M[n][n]; // 頂点数がnのグラフを表す隣接行列
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      M[i][j] = 0;
    }
  }
  
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    u--;
    v--;
    M[u][v] = 1;
    M[v][u] = 1; // 有向グラフではこの行をコメントアウト
  }
  
  vector<int> x(n);
  for(int i = 0; i < n; i++) x.at(i) = i;
  
  int ans = 0;
  for(ll i = 0; i < factorial(n - 1); i++){
    bool judge = true;
    for(int j = 1; j < n; j++){
      if(M[x.at(j - 1)][x.at(j)] == 0) judge = false;
    }
    if(judge) ans++;
    next_permutation(x.begin(), x.end());
  }
  
  cout << ans << '\n';
}