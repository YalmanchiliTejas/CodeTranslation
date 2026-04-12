#include <iostream>
#include <vector>

using namespace std;

#define debug(x) cout << #x << "==" << x << endl;

typedef long long ll;

#define MAX_V 10000
vector<int> G[MAX_V];


void dfs(int v, vector<int> visited, int &res) {


  if( visited[v] ) return;
  visited[v] = true;

  bool all_visited = true;
  for( bool b : visited ) { all_visited = b && all_visited; }
  if( all_visited ) { res++; }

  for(int w : G[v]) {
    dfs(w, visited, res);
  }

}


int main() {
  ios::sync_with_stdio(false);

  int V, E;
  cin >> V >> E;

  for(int i = 0; i < E; i++) {
    int v, w;
    cin >> v >> w;
    v--; w--;
    G[v].push_back(w);
    G[w].push_back(v);
  }

  vector<int> visited(V, false);
  int res = 0;
  dfs(0, visited, res);

  cout << res << "\n";

  return 0;
}
