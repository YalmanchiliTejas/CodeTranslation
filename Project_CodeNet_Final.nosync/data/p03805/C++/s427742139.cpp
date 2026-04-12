#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n, m;

  vector<int> visited;
  vector<vector<int>> g;
  int num_visited = 0;
  int ans = 0;

  void dfs(int now){
    visited[now] = 1;
    num_visited++;

    if(num_visited == n){
      ans++;
    }
    for(int i=0; i<g[now].size(); i++){
      int next = g[now][i];
      if(! visited[next]) dfs(next);
    }
    visited[now] = 0;
    num_visited--;
  }

int main()
{
  
  cin >> n >> m;
  g = vector<vector<int> > (n);
  visited = vector<int> (n, 0);
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;

    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0);
  cout << ans << endl;
  

  return 0;
}