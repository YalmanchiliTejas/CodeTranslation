#include <bits/stdc++.h>
using namespace std;

long long ans;
bool graph[10][10],visited[10];

void dfs(int now, int n){

  bool all_visited=true;
  for(int i=0;i<n;i++){
    if(!visited[i]){
      all_visited=false;
    }
  }
  if(all_visited){
    ans++;
    return ;
  }
  for(int i=0;i<n;i++){
    if(now!=i and graph[now][i] and !visited[i]){
      visited[i]=true;
      dfs(i, n);
      visited[i]=false;
    }
  }
  return ;
}

int main(){
  int n,m;
  cin >> n >> m;
  int a[m],b[m];
  for(int i=0;i<m;i++){
    cin >> a[i] >> b[i];
    a[i]--;b[i]--;
    graph[a[i]][b[i]]=graph[b[i]][a[i]]=true;
  }
  visited[0]=true;
  dfs(0, n);
  cout << ans << endl;
  return 0;
}
