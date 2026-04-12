#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(8, vector<int>(8));
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    g[a-1][b-1] = g[b-1][a-1] = 1;
  }
  vector<int> node;
  for(int i = 0; i < n; i++){
    node.push_back(i);
  }
  int ans = 0;
  bool ok;
  do{
    ok = true;
    for(int i = 0; i < n-1; i++){
      if(g[node[i]][node[i+1]] == 0) ok = false;
    }
    if(ok) ans++;
  }while(next_permutation(node.begin()+1, node.end()));
  cout << ans << endl;
}