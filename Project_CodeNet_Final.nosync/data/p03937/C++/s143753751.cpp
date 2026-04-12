#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )

int dp[8][8][64];
char grid[8][8];
int H, W;
int cnt = 0;

int dfs(int x, int y, int c) {
  // cout << x << " " << y << " " << c << endl;
  if ( dp[x][y][c] >= 0 ) return dp[x][y][c];
  if ( x == W-1 && y == H-1 ) {
    
    if ( c == cnt-1 ) return 1;
    else return 0;
  }

  int ret = 0;
  if ( x < W-1 ) ret |= dfs(x+1, y, c+(grid[y][x+1] == '#'));
  if ( y < H-1 ) ret |= dfs(x, y+1, c+(grid[y+1][x] == '#'));

  return dp[x][y][c] = ret;  
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> H >> W;
  REP(i, H) REP(j, W) {
    cin >> grid[i][j];
    if ( grid[i][j] == '#' ) cnt++;
  }

  fill_n(**dp, 8*8*64, -1);

  int ans = dfs(0, 0, 0);
  if ( ans > 0 ) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  
  return 0;
}
