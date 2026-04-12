#include<iostream>
#include<vector>
using namespace std;
bool graph[8][8];
int dfs(int v,int n,bool visited[8]){
  bool all=true;
  int r=0;
  for(int i=0;i<n;i++){
    if(visited[i]==false){
      all=false;
      break;
    }
  }
  if(all==true) return 1;
  for(int i=0;i<n;i++){
    if(graph[v][i]==false || visited[i]==true) continue;
    visited[i]=true;
    r+=dfs(i,n,visited);
    visited[i]=false;
  }
  return r;
}
int main(){
  int n,m,temp_m,temp_n;
  bool visited[8];
  cin >> n >>m;
  for(int i=0;i<m;i++){
    cin >> temp_n>>temp_m;
    graph[temp_n-1][temp_m-1]=graph[temp_m-1][temp_n-1]=true;
    visited[i]=false;
  }
  visited[0]=true;
  cout << dfs(0,n,visited)<<endl;
}
