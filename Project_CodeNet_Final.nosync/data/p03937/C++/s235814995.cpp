#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int H, W;
  cin >> H >> W;
  char A[10][10];

  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
      if (A[i][j] == '#') {
        ans++;
      }
    }
  }
  
  if (ans == H + W - 1) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}