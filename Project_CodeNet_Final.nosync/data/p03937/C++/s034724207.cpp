#include <iostream>
#define REP(i, a, n) for(int i = a; i <= n; i++)
using namespace std;


int H, W;
char A[10][10];

int main(void) {
  cin >> H >> W;
  REP(i, 0, H - 1) {
    cin >> A[i];
  }

  bool flag = true;
  REP(i, 0, H - 1) {
    REP(j, 0, W - 1) {
      if(i + 1 < H && j + 1 < W && A[i + 1][j] == '#' && A[i][j + 1] == '#')
        flag = false;
    }
  }

  cout << (flag ? "Possible" : "Impossible") << endl;

  return 0;
}
