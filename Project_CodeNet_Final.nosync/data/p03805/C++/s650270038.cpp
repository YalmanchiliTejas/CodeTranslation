#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>> G(8,vector<bool>(8));
vector<bool> seen;

int dfs(int v,int n, vector<bool> seen){
  bool all_seen = true;
  for(int i = 0; i < n; i++){
    if(seen.at(i)==false) all_seen = false;
  }
  if(all_seen) return 1;
  
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(G[v][i] == false) continue;
    if(seen[i]) continue;
   // printf("next_v:%d\n",next_v);
    seen[i] = true;
    ans +=dfs(i,n,seen);
    seen[i] = false;
  }
  return ans;  
}
int main(){
  int n,m; cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a,b; cin >> a >> b;
    a--;b--;
    G[a][b] = true;
    G[b][a] = true;
  }

  seen.assign(n,false);
  seen.at(0) = true;
  cout << dfs(0,n,seen) << endl;
}
  
  