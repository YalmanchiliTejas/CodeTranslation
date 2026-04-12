#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  bool g[n][n] = {};
  for(int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    a--;b--;
    g[a][b] = g[b][a] = true;
  }
  vector<int> p(n);
  for(int i = 0; i < n; i++){
    p[i] = i;
  }
  int ans = 0;
  do{
    if(p[0] != 0) break;
    bool ok = true;
    for(int i = 0; i < n-1; i++){
      int from = p[i];
      int to = p[i+1];
      if(!g[from][to]) ok =false;
    }
    if(ok) ans++;
  }while(next_permutation(p.begin(), p.end()));
  cout << ans << endl;
  return 0;
}
