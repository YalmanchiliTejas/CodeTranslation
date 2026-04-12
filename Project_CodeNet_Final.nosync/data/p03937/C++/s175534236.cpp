#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;
  vector<vector<char>> field(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> field[i][j];
    }
  }
  int cnt = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (field[i][j] == '#')
        cnt++;
    }
  }
  if (cnt == H + W - 1)
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
}
