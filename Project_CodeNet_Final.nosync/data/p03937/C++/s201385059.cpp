//今調べているマスが'#'であり,かつ左下に#が存在したらImpossible (f = true)
#include <bits/stdc++.h>
using namespace std;
int main() {
  bool f = false;
  int H, W;
  cin >> H >> W;
  char a[10][10];
  for (int i = 0; i < H; i++)  {
    for (int j = 0; j < W; j++)  {
        cin >> a[i][j];
    }
  }
  //全部のマスを調べていく
  for (int i = 0; i < H; i++)  {
    for (int j = 0; j < W; j++)  {
      if (0 <= i < H && 0 <= j < W) {
        if (a[i][j] == '#' && a[i+1][j-1] == '#') f = true;
  //調べた所は全て'.'と置く           
          a[i][j] = '.';
             }
    }
    }
if(f) cout << "Impossible" << endl;
else cout << "Possible" << endl;
}