#include <bits/stdc++.h>
using namespace std;
const int vy[] = {0, 1, 0, -1}, vx[] = {1, 0, -1, 0};

int H, W, M, cost[3][50][50];
string S[50];
int last[50][50];

bool isgo(int x, int y)
{
  return(0 <= x && x < W && 0 <= y && y < H && S[y][x] == '.');
}

int getCost(int x, int y, int time)
{
  int pv = last[y][x];
  last[y][x] = time;
  if(~pv) {
    return(min(cost[1][y][x] + cost[2][y][x], (time - pv) * cost[0][y][x]));
  } else {
    return(cost[1][y][x] + cost[2][y][x]);
  }
}
int addPath(int px, int py, int x, int y, const int gx, const int gy, int& time)
{
  if(x == gx && y == gy) return(0);
  for(int i = 0; i < 4; i++) {
    int ny = y + vy[i], nx = x + vx[i];
    if((ny != py || nx != px) && isgo(nx, ny)) {
      int ntime = time + 1;
      int next = addPath(x, y, nx, ny, gx, gy, ntime);
      if(~next) {
        int poyo = next + getCost(x, y, time);
        time = ntime;
        return(poyo);
      }
    }
  }
  return(-1);
}

int main()
{
  memset(last, -1, sizeof(last));
  cin >> H >> W >> M;
  for(int i = 0; i < H; i++) {
    cin >> S[i];
  }
  for(int k = 0; k < 3; k++) {
    for(int i = 0; i < H; i++) {
      for(int j = 0; j < W; j++) {
        cin >> cost[k][i][j];
      }
    }
  }
  int py, px, ret = 0, time = 1;
  for(int i = 0; i < M; i++) {
    int y, x;
    cin >> y >> x;
    if(i > 0) ret += addPath(-1, -1, px, py, x, y, time);
    py = y, px = x;
  }
  cout << ret + getCost(px, py, time) << endl;  
}