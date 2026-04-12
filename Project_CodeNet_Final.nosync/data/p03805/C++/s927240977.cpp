#include <bits/stdc++.h>
using namespace std;

const int NMAX = 8;

vector<vector<bool>> graph(NMAX, vector<bool> (NMAX, false));

int dfs(int v, int n, vector<bool> visit){
  bool all_visit = true;
  
  for(int i = 0; i < n; i++){
    if(!visit[i]) all_visit = false;
  }
  
  if(all_visit) return 1;
  
  int ret = 0;
  
  for(int i = 0; i < n; i++){
    if(!graph[v][i]) continue;
    if(visit[i]) continue;
    
    visit[i] = true;
    ret += dfs(i, n, visit);
    visit[i] = false;
  }
  
  return ret;
  
}

int main(){
  int n, m; cin >> n >> m;
  vector<bool> visit(n, false);
  
  for(int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    graph[a][b] = graph[b][a] = true;
  }
  
  visit[0] = true;
  cout << dfs(0, n, visit) << endl;

}