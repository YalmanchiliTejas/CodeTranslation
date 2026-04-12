#include <bits/stdc++.h>
using namespace std;

vector<int> G[10];
int d[10]={};
int n, m;
int ans = 0;

void dfs(int now){
  d[now] = 1;
  int cnt = 1;
  for(int i=0; i<n; i++){
    cnt *= d[i];
  }
  ans += cnt;
  for(int i=0; i<G[now].size(); i++){
    int next = G[now][i];
    if(d[next]==0) dfs(next);
  }
  d[now] = 0;
}
 
int main(){
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(0);
  cout << ans << endl;
  return 0;
}