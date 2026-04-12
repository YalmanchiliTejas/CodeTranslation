#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> a(h);
  for (int i = 0; i < h; i++) {
      cin >> a[i];
  }

  for (int i = 0; i < h; i++) {
    int count = 0;
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '.') {
        count++;
      }
    }
    if (count == w) {
      for (int j = 0; j < w; j++) {
        a[i][j] = ' ';
      }
    }
  }

  for (int i = 0; i < w; i++) {
    int count = 0;
    for (int j = 0; j < h; j++) {
      if (a[j][i] == '.' || a[j][i] == ' ') {
        count++;
      }
    }
    if (count == h) {
      for (int j = 0; j < h; j++) {
        a[j][i] = ' ';
      }
    }
  }

  for (int i = 0; i < h; i++) {
    bool flag = false;
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#' || a[i][j] == '.') {
        cout << a[i][j];
        flag = true;
      }
    }
    if (flag) {
      cout << endl;
    }
  }
}