#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;

  char A[H][W];
  for (int i=0; i<H; ++i) {
    for (int j=0; j<W; ++j) cin >> A[i][j];
  }

  int H_rest[H];
  int W_rest[W];

  for (int i=0; i<H; ++i) H_rest[i]=i;
  for (int j=0; j<W; ++j) W_rest[j]=j;

  bool isWhite;

  //行チェック
  for (int i=0; i<H; ++i) {
    isWhite = true;
    for (int j=0; j<W; ++j) {
      if (A[i][j] == '#') {
        isWhite = false;
        break;
      }
    }
    if (isWhite) {
      H_rest[i] = -1;
    }
  }
  //列チェック
  for (int j=0; j<W; ++j) {
    isWhite = true;
    for (int i=0; i<H; ++i) {
      if (A[i][j] == '#') {
        isWhite = false;
        break;
      }
    }
    if (isWhite) {
      W_rest[j] = -1;
    }
  }

  //Output
  for (int i=0; i<H; ++i) {
    if (H_rest[i] == -1) {
      continue;
    }
    else {
      for (int j=0; j<W; ++j) {
        if (W_rest[j] == -1) {
          continue;
        }
        else {
          cout << A[i][j];
        }
      }
      cout << endl;
    }
  }

  return(0);
}
