#include <bits/stdc++.h>

#define stirng string
#define vvi vector<vector<int>>
#define vi vector<int>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

const int inf = 1e9 + 7;

int main() {
  int h, w;
  cin >> h >> w;
  char mas[h][w];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> mas[i][j];
    }
  }
  int count;
  for (int i = 0; i < h; i++) {
    count = 0;
    for (int j = 0; j < w; j++) {
      if (mas[i][j] == '.') {
        count++;
      }
    }
    if (count == w) {
      for (int k = 0; k < w; k++) {
        mas[i][k] = '*';
      }
    }
  }

  for (int i = 0; i < w; i++) {
    count = 0;
    for (int j = 0; j < h; j++) {
      if (mas[j][i] == '.' || mas[j][i] == '*') {
        count++;
      }
    }
    if (count == h) {
      for (int k = 0; k < h; k++) {
        mas[k][i] = '*';
      }
    }
  }

  count = 0;
  int flag = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (mas[i][j] == '*') {
        count++;
        continue;
      } else {
        cout << mas[i][j];
      }
    }
    if (count == w) {
      flag = 1;
    }
    if (flag == 0) {
      cout << endl;
    }
    flag = 0;
    count = 0;
  }

  return 0;
}
