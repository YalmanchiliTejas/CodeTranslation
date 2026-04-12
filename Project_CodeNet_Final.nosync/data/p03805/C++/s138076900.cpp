#include <iostream>
using namespace std;

const int nlimit=10;
int n, m;
bool graph[nlimit][nlimit];
bool visited[nlimit];

int dfs(int, int);
int main(){
  cin >> n >> m;
  int a, b;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    graph[a][b] = true;
    graph[b][a] = true;
  }

  int ans = dfs(1, 0);

  cout << ans << endl;

  return 0;
}

int dfs(int start, int path){
  if(visited[start]) return 0;
  if(path==n-1){
    for(int i=1; i<=n; i++){
      if(!visited[i] && i!=start) return 0;
    }
    return 1;
  }

  visited[start] = true;

  int cnt=0;
  for(int i=1; i<=n; i++){
    if(graph[start][i]) cnt += dfs(i, path+1);
  }

  visited[start] = false;

  return cnt;
}
