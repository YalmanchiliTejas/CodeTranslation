#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  for (int i = 0; i < H; i++) cin >> a[i];

  vector<vector<bool>> flag(H, vector<bool>(W));
  for (int i = 0; i < H; i++) {
    int white_n = 0;
    for (int j = 0; j < W; j++) {
      if (a[i][j] == '.') white_n++;
    }

    if (white_n == W) {
      for (int j = 0; j < W; j++) flag[i][j] = true;
    }
  }

  for (int i = 0; i < W; i++) {
    int white_n = 0;
    for (int j = 0; j < H; j++) {
      if (a[j][i] == '.') white_n++;
    }

    if (white_n == H) {
      for (int j = 0; j < H; j++) flag[j][i] = true;
    }
  }

  for (int i = 0; i < H; i++) {
    int cout_n = 0;
    for (int j = 0; j < W; j++) {
      if (flag[i][j] == false && j == W - 1) {
        cout << a[i][j] << endl;
        cout_n++;
      } else if (flag[i][j] == false) {
        cout << a[i][j];
        cout_n++;
      } else if (j == W - 1 && cout_n >= 1) cout << endl;
    }
  }

  return 0;
}
