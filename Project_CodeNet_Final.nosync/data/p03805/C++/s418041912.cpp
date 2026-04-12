#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>>graph(8,vector<bool>(8));

int dfs(int v,int n,vector<bool>&visited){
  bool all_visited= true;
  for(int i:visited){
    if(i!=true){
      all_visited =false;
    }
  }
  if(all_visited){
    return 1;
  }
  int rep=0;
  for(int i=0;i<n;i++){
    if(graph.at(v).at(i) ==false){
      continue;
    }
    if(visited.at(i)){
      continue;
    }
    visited.at(i) =true;
    rep +=dfs(i,n,visited);
    visited.at(i) =false;
  }
  return rep;
}
 
int main() {
  int n,m;
  cin >>n >>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >>b;
    graph.at(a-1).at(b-1)=graph.at(b-1).at(a-1)=true;
  }
  vector<bool>visited(n);
  visited.at(0)=true;
  cout << dfs(0,n,visited);
}