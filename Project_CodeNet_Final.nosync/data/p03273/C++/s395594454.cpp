#include <iostream>
#include <string>
using namespace std;
int main() {
  int H, W;
  string S[100];
  ios::sync_with_stdio(false);
  cin >> H >> W;
  for (int i=0; i<H; i++) {
    cin >> S[i];
  }
  int r[100], c[100];
  for (int i=0; i<H; i++) {
    r[i] = 0;
    for (int j=0; j<W; j++) {
      if (S[i][j] == '#') {
        r[i] = 1;
        break;
      }
    }
  }
  for (int j=0; j<W; j++) {
    c[j] = 0;
    for (int i=0; i<H; i++) {
      if (S[i][j] == '#') {
        c[j] = 1;
        break;
      }
    }
  }
  for (int i=0; i<H; i++) {
    if (!r[i]) continue;
    for (int j=0; j<W; j++) {
      if (!c[j]) continue;
      cout << S[i][j];
    }
    cout << '\n';
  }
}