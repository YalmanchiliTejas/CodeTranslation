#include <bits/stdc++.h>
#define loop(i, n) for(int i = 0; i < int(n); i++)
#define rep(i, begin, end) for(int i = int(begin); i < int(end); i++)
using namespace std;

int main() {
  int H, W, cntH, cntW;
  char tmp;
  cin >> H >> W;

  bool is_black[H][W], is_remain[2][max(H, W)];
  loop(i, H) {
    loop(j, W) {
      cin >> tmp;
      tmp == '#' ? is_black[i][j] = true : is_black[i][j] = false;
    }
  }

  loop(i, 2) {
    loop(j, max(H, W)) {
      is_remain[i][j] = false;
    }
  }

  loop(i, H){
    loop(j, W) {
      is_black[i][j] ? is_remain[0][i] = true : 0;
      is_black[i][j] ? is_remain[1][j] = true : 0;
    }
  }

  loop(i, H) {
    if (is_remain[0][i]) {
      loop(j, W) {
        if (is_remain[1][j]) {
          cout << (is_black[i][j] ? "#" : ".");
        }
      }
      cout << endl;
    }
  }

  return 0;
}
