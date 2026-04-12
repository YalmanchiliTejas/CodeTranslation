#include <iostream>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int A[101][101];

int main() {
  int H, W;
  char a;
  cin >> H >> W;
  REP(j, H) {
    REP(i, W) {
      cin >> a;
      A[j][i] = a == '#' ? 1 : 0;
    }
  }
  REP(j, H) {
    int c = 0;
    REP(i, W) {
      if (A[j][i] == 0) {
        c++;
      }
    }
    if (c == W) {
      REP(i, W) { A[j][i] = -1; }
    }
  }

  REP(i, W) {
    int c = 0;
    REP(j, H) {
      if (A[j][i] == 0 || A[j][i] == -1) {
        c++;
      }
    }
    if (c == H) {
      REP(j, H) { A[j][i] = -1; }
    }
  }

  REP(j, H) {
    int c = 0;
    REP(i, W) {
      if (A[j][i] == -1) {
        c++;
        continue;
      }
      cout << (A[j][i] == 0 ? '.' : '#');
    }
    if (c != W)
      cout << endl;
  }
}