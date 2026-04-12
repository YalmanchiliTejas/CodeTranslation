#include <bits/stdc++.h>
using namespace std;
int G[10][10];
int n,m;
int used[10];

bool check(){
  for(int i=0;i<n;i++) if(used[i] == 0) return 0;
  return 1;
}

int dfs(int pos){
  if(check()) return 1;
  
  int res=0;
  for(int i=0;i<n;i++){
    if(G[pos][i] == 0|| used[i]) continue;
    used[i] = 1;
    res+=dfs(i);    
    used[i] = 0;
  }
  return res;
}

int main(){

  cin>>n>>m;					
  for(int i=0,a,b;i<m;i++){
    cin>>a>>b;a--,b--;
    G[a][b] = G[b][a] = 1;
  }
  used[0] = 1;
  cout <<dfs(0)<<endl;

  return 0;
}
