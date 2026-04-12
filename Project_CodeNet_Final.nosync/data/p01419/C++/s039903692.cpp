#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 50;

int h, w, m, co[3][N][N], r, c, pr, pc, t;
char da[N][N];
vector<int> ti[N][N];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
bool vis[N][N];

int move(int y, int x, int cnt){
  if(y == r && x == c) return cnt;
  vis[y][x] = true;
  for(int i=0;i<4;i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
    if(da[ny][nx] == '#') continue;
    if(vis[ny][nx]) continue;
    int res = move(ny, nx, cnt+1);
    if(res >= 0){
      ti[y][x].push_back(t + cnt);
      return res;
    }
  }
  return -1;
}

main(){
  cin >> h >> w >> m;
  for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin >> da[i][j];
  for(int k=0;k<3;k++) for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin >> co[k][i][j];
  pr = -1;
  t = 0;
  for(int i=0;i<m;i++){
    cin >> r >> c;
    fill(vis[0], vis[N], false);
    if(pr != -1) t += move(pr, pc, 0);
    pr = r;
    pc = c;
    if(i + 1 == m) ti[r][c].push_back(t);
  }
  int ans = 0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      for(int k=0;k<ti[i][j].size();k++){
        if(k > 0 && co[1][i][j] + co[2][i][j] > co[0][i][j] * (ti[i][j][k] - ti[i][j][k-1]))
          ans += co[0][i][j] * (ti[i][j][k] - ti[i][j][k-1]);
        else ans += co[1][i][j] + co[2][i][j];
      }
    }
  }
  cout << ans << endl;
}