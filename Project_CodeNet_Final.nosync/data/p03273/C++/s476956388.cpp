#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  char a[H][W];
  vector<bool> isW(W, false);
  vector<bool> isH(H, false);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
      if (a[i][j] == '#') isH[i] = true;
      if (a[i][j] == '#') isW[j] = true;
    }
  }
  for (int i = 0; i < H; i++) {
    if (isH[i] == true) {
      for (int j = 0; j < W; j++) {
        if (isW[j] == true) cout << a[i][j] << flush;
      }
      cout << endl;
    }
  }
}