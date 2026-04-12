#include <bits/stdc++.h>
using namespace std;

int used[8];
int n, m;
vector<vector<int>> edge;

int dfs(int cur){
  bool flag = true;
  int res = 0;
  for(int i = 1; i < n; i++){
    if(used[i] == 0) flag = false;
  }
  if(flag) return 1;
  for(int i = 0; i < edge[cur].size(); i++){
    if(used[edge[cur][i]]) continue;
    used[edge[cur][i]] = 1;
    res += dfs(edge[cur][i]);
    used[edge[cur][i]] = 0;
  }
  return res;
}

int main(){
  cin >> n >> m;
  edge.resize(n);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  used[0] = 1;
  cout << dfs(0) << endl;
  return 0;
}
