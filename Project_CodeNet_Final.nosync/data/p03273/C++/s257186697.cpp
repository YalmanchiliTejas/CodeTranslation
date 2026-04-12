#include <iostream>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  char a[h][w];
  bool h_output[h] = {false}, w_output[w] = {false};
  int i, j;
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      cin >> a[i][j];
      if (a[i][j] == '#') {
        h_output[i] = true;
        w_output[j] = true;
      }
    }
  }
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      if (h_output[i] && w_output[j]) {
        cout << a[i][j];
      }
    }
    if (h_output[i]) {
      cout << endl;
    }
  }
  return 0;
}
