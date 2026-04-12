#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  int r = 0;
  string a;
  for (int i = 0; i < H; i++) {
    cin >> a;
    for (int j = 0; j < W; j++) {
      if (j < r && a[j] == '#') {
        cout << "Impossible" << endl;
        return 0;
      } else if (a[j] == '#') {
        r = j;
      }
    }
  }
  cout << "Possible" << endl;
}