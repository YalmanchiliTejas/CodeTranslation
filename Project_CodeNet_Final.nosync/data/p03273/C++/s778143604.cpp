#include <algorithm>
#include <iostream>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX_H 110
#define MAX_W 110
bool ignoreH[MAX_H];
bool ignoreW[MAX_W];
int main() {
  int H, W;
  cin >> H >> W;
  string sq[H];
  REP(i, H) cin >> sq[i];
  REP(i, H) {
    ignoreH[i] = true;
    REP(j, W) {
      if (sq[i][j] == '#') {
        ignoreH[i] = false;
        break;
      }
    }
  }

  REP(j, W) {
    ignoreW[j] = true;
    REP(i, H) {
      if (sq[i][j] == '#') {
        ignoreW[j] = false;
        break;
      }
    }
  }

  REP(i, H) {
    REP(j, W) {
      if (ignoreH[i]) continue;
      if (ignoreW[j]) continue;
      cout << sq[i][j];
    }
    if (!ignoreH[i]) cout << endl;
  }

  return 0;
}