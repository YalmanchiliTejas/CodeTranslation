// Last Change:       11/29/2018 18:45:55.
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <list>
#include <memory>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  char a[100][100];
  int hhh[100], www[100];
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    hhh[i] = 0;
  }
  for (int i = 0; i < W; i++) {
    www[i] = 0;
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
      if (a[i][j] == '#') {
        hhh[i]++;
        www[j]++;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    if (hhh[i]) {
      for (int j = 0; j < W; j++) {
        if (www[j]) {
          cout << a[i][j];
        }
      }
      cout << "\n";
    }
  }
  cout << flush;
}
