#include<bits/stdc++.h>
using namespace std;
bool adj_mtrix[8][8];
int dfs(int v, int n, bool achieved[8]){
  bool all_achieved = true;
  for(int i=0; i<n; ++i){
    if(!achieved[i]) all_achieved = false;
  }
  if( all_achieved) return 1;
  int ret = 0;
  for(int i=0; i<n; ++i){
    if( !adj_mtrix[v][i] ) continue;
    if( achieved[i] ) continue;
    achieved[i] =true;
    ret += dfs(i, n, achieved); 
    achieved[i] =false;
  }
  return ret;
}
int main(){
  int n,m; cin>>n>>m;
  bool achieved[n];
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      adj_mtrix[i][j] = false;
    }
    achieved[i] = false;
  }
  for(int i=0; i<m; ++i){
    int a,b;
    cin>>a>>b;
    adj_mtrix[a-1][b-1] = adj_mtrix[b-1][a-1] = true;
  }
  achieved[0] =true;
  cout << dfs(0, n, achieved)<<endl;
  return 0;
}