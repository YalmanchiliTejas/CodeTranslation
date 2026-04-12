#include <iostream>
using namespace std;

const int nlimit=10;
int n, m;
bool graph[nlimit][nlimit];
bool visited[nlimit];

int dfs(int);
int main(){
  cin >> n >> m;
  int a, b;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    graph[a][b] = true;
    graph[b][a] = true;
  }

  int ans = dfs(1);

  cout << ans << endl;

  return 0;
}

int dfs(int start){
  visited[start] = true;
  bool f=true;
  for(int i=1; i<=n; i++){
    f = f&&visited[i];
  }
  if(f) {
    visited[start] = false;
    return 1;
  }

  int cnt=0;
  for(int i=1; i<=n; i++){
    if(graph[start][i] && !visited[i]) {
      cnt += dfs(i);
    }
  }

  visited[start] = false;

  return cnt;
}
