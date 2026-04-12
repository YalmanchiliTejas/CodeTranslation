#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <utility>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long int H, W; cin >> H >> W;
  char a[110][110];
  for (int j = 0; j < H; j++) {
    for (int i = 0; i < W; i++)
      cin >> a[j][i];
  }
  int h[110]; int w[110];
  for (int i = 0; i < 110; i++) {
    h[i] = 1; w[i] = 1;
  }
  for (int i = 0; i < W; i++) {
    int c = 0;
    for (int j = 0; j < H; j++)
      c += (a[j][i] == '.');
    if (c == H)
      w[i] = 0;
  }
  for (int j = 0; j < H; j++) {
    int c = 0;
    for (int i = 0; i < W; i++)
      c += (a[j][i] == '.');
    if (c == W)
      h[j] = 0;
  }
  for (int j = 0; j < H; j++) {
    for (int i = 0; i < W; i++) {
      if (!(h[j] == 0 || w[i] == 0))
        cout << a[j][i];
    }
    if (h[j] != 0)
      cout << endl;
  }
}
