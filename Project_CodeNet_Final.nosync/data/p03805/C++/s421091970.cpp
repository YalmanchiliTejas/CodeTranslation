#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int limit=8;
vector<int>to[limit];
vector<bool>visited(limit,false);

int dfs(int v, int n){
  bool all = true;
  int res = 0;
  visited[v]=true;
  for(int i=0; i<n; i++){
   if(visited[i]==false) all=false; 
   //cout << v << " " << visited[i] << endl;
  }
  
  if(all){
    visited[v]=false;
    return 1;
  }
  
  for(int i=0; i<to[v].size(); i++){
    if(visited[to[v][i]])continue;
    //cout << i << "  "  << to[v][i] << endl;
    res+=dfs(to[v][i],n);
  }
  visited[v]=false;
  return res;
}

int main(){
  int n,m;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int x,y;
    cin >> x >> y;
    x--; y--;
    to[x].push_back(y);
    to[y].push_back(x);
  }
  cout << dfs(0,n) << endl;
  return 0;
  
}