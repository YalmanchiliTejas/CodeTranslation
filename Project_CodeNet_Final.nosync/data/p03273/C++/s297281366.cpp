#include <iostream>
#include <string>
using namespace std;

int H, W;
string board[110];
bool goodx[110], goody[110];

int main(void) {
  cin >> H >> W;

  for (int i = 0; i < H; i++) {
    cin >> board[i];
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (board[i][j] == '#') {
        goodx[i] = true;
        goody[j] = true;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    if (goodx[i]) {
      for (int j = 0; j < W; j++) {
        if (goody[j]) {
          cout << board[i][j];
        }
      }
      cout << endl;
    }
  }

  return 0;
}