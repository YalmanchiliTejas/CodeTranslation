#include <iostream>
#include <vector>

using namespace std;

const int max_int = 10;
bool G[max_int][max_int];

int visit(int v, int n, vector<bool> &visited){
  bool all_visited = true;
  for(int i = 0; i < visited.size(); i++){
    if(visited[i] == false) all_visited = false;
  }
  
  int ret = 0;
  if(all_visited) return 1;
  else{
    for(int j = 0; j < n ;j++){
      if(G[v][j] == false) continue;
      if(visited[j]) continue;
      visited[j] = true;
      ret += visit(j, n, visited); 
      visited[j] = false;
    }
    return ret;
  }
  
}
 
int main(){
  int N, M;
  cin >> N >> M;
    
  for(int i = 0; i < M; i++){
    int a = 0, b = 0;
    cin >> a >> b;
    a--, b--;
    G[a][b] = G[b][a] = true;
  }//グラフ読み込み
  
  vector<bool> visited(N,false);
  //頂点1からスタート
  visited[0] = true;
  int ans = visit(0, N, visited);
  cout << ans;
}
