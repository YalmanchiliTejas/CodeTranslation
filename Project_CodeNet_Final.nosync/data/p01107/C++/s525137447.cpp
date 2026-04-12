#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
char g[55][55];
bool v[55][55];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
 
bool dfs(int y, int x, int dir, int num)
{
  if(y < 0 || x < 0 || y >= n || x >= m || g[y][x] == '#') return(false);
  if(v[y][x]++) return(false);
  if(num == 0 && y == 0 && x == m - 1) ++num;
  if(num == 1 && y == n - 1 && x == m - 1) ++num;
  if(num == 2 && y == n - 1 && x == 0) ++num;
  if(num == 3 && y == 1 && x == 0) ++num;
  if(num == 4) return(true);
  (dir += 3) %= 4;
  for(int i = 0; i < 4; i++, (dir += 1) %= 4) {
    if(dfs(y + dy[dir], x + dx[dir], dir, num)) return(true);
  }
  return(false);
}
 
int main()
{
  for(;;) {
    scanf("%d%d", &n, &m);
    if(n + m == 0) break;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) scanf(" %c", g[i] + j);
    }
    memset(v, false, sizeof(v));
    puts(dfs(0, 0, 1, 0) ? "YES" : "NO");
  }
  return 0;
}