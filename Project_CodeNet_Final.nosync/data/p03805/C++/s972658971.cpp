#include <iostream>
#include <vector>
using namespace std;


int dfs(int now, const vector<vector<bool> >& graph, vector<bool> visited){
  bool all_visited = true;
  int n = graph.size();
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      all_visited = false;
      i = n;
    }
  }
  if(all_visited) return 1;

  int ans = 0;
  for(int i = 0; i < n; i++){
    if(!graph[now][i]) continue;
    if(visited[i]) continue;

    visited[i] = true;
    ans += dfs(i, graph, visited);
    visited[i] = false;
  }
  // cout << "now: " << now << " ans:" << ans << endl;
  return ans;
}

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<bool> > graph(n, vector<bool>(n, false));
  for(int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    graph[a][b] = graph[b][a] = true;
  }

  vector<bool> visited(n, false);
  visited[0] = true;
  cout << dfs(0, graph, visited) << endl;

}
