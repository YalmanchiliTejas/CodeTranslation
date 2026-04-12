#include <iostream>
#define REP(i,n) for(int i = 0; i < (n); i++)

using namespace std;

char mp[10][10];

int main()
{
  int H, W;
  cin >> H >> W;
  REP(i, H) REP(j, W) cin >> mp[i][j];

  int y = 0, x = 0;
  bool flag = true;
  mp[0][0] = '.';
  while (1) {
    if (y == H-1 && x == W-1) break;
    if (x+1 < W && mp[y][x+1] == '#') {
      mp[y][x+1] = '.';
      x++;
    } else if (y+1 < H && mp[y+1][x] == '#') {
      mp[y+1][x] = '.';
      y++;
    } else {
      flag = false;
      break;
    }
  }
  REP(i, H) {
    REP(j, W) {
      if (mp[i][j] == '#') {
        flag = false;
        break;
      }
    }
  }
  if (flag) cout << "Possible" << endl;
  else cout << "Impossible" << endl;

  return 0;
}