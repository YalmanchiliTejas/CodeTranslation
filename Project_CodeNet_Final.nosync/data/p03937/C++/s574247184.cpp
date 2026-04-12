#include<cstdio>
using namespace std;

int n, m;
char arr[10][10];
bool vis[10][10];

bool dfs(int x, int y) {
  bool ret = false;
  vis[x][y] = true;
  if(x == n-1 && y == m-1) {
    for(int i = 0 ; i < n ; i++)
      for(int j = 0 ; j < m ; j++) {
        if(arr[i][j] == '#' && vis[i][j] != true) {
          return false;
        }
      }
    return true;
  }
  if(arr[x+1][y] == '#') ret = dfs(x+1, y);
  if(ret) return true;
  if(arr[x][y+1] == '#') ret = dfs(x, y+1);
  vis[x][y] = false;
  return ret;
}

int main(){
  scanf("%d %d", &n, &m);
  for(int i = 0 ; i < n ; i++){
    scanf("%s", arr[i]);
  }
  bool get = dfs(0,0);
  if(get) puts("Possible");
  else puts("Impossible");
  return 0;
}
