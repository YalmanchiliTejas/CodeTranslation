//AGC 007-A(解２(H+W-1)個のマスを通ることと問題の条件を満たすことは同値)
#include <bits/stdc++.h>
using namespace std;
int main() {
  int H, W;
  cin >> H >> W;
  char a[10][10];
  for (int i = 0; i < H; i++)  {
    for (int j = 0; j < W; j++)  {
        cin >> a[i][j];
    }
  }
  int kosuu = 0;
  for (int i = 0; i < H; i++)  {
    for (int j = 0; j < W; j++)  {
      if (a[i][j] == '#') ++kosuu;
    }
  }
  if (kosuu == H + W - 1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}