#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool g[10][10];
bool color[10];

int dfs(int v, int n){

  bool flag = true;

  for(int i = 0; i < n; i++){
    if(color[i] == false){
      flag = false;
    }
  }
  
  if(flag) return 1;
  int res = 0;

  for(int i = 0; i < n; i++){
    if(g[v][i] == false) continue;
    if(color[i]) continue;
    color[i] = true;
    res += dfs(i, n);
    color[i] = false;
  }
  return res;
}

int main(){

  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    int from, to;
    cin >> from >> to;
    from--; to--;
    g[from][to] = g[to][from] = true;
  }

  fill(color, color+10, false);
  color[0] = true;

  int ans = dfs(0, n);

  cout << ans << endl;
  return 0;
}
