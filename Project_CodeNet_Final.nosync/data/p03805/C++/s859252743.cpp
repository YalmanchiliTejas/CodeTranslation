#include<bits/stdc++.h>

using namespace std;
int ans,N,M;
bool graph[10][10];
void dfs(vector<bool> vis, int current, int visCnt){
  if(visCnt == N){
    ans ++;
    return;
  }
  for(int i = 0; i < N; i++){
    if(graph[current][i] && vis[i] == false){
      vis[i] = true;
      dfs(vis,i,visCnt + 1);
      vis[i] = false;
    }
  }
  return ;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
      int to,from;
      cin >> to >> from;
      to--; from--;
      graph[to][from] = true;
      graph[from][to] = true;
    }
    vector<bool> vis(N,false);
    vis[0] = true;
    dfs(vis,0,1);
    cout << ans << endl;
    return 0;
}
