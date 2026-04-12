#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w; cin >> h >> w;
  vector<string> grid(h);
  vector<bool> height(h);
  vector<bool> width(w);
  for (int i = 0; i < h; i++) {
    cin >> grid.at(i);
  }

  if (h <= 2 && w == 1 || h == 1 && w <= 2) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (j != w - 1) {
        if (grid.at(i).at(j) != '.') cout << grid.at(i).at(j);
        }
        else {
          if (grid.at(i).at(j) != '.') cout << grid.at(i).at(j) << endl;
          else cout << endl;
        }
      }
    }
  }
  else {
    for (int i = 0; i < h; i++) {
      int check = 0;
      for (int j = 0; j < w - 1; j++) {
        if (grid.at(i).at(j) == '.' && grid.at(i).at(j + 1) == '.') check++;
      }
      if (check == w - 1) height.at(i) = false;
      else height.at(i) = true;
    }

    for (int i = 0; i < w; i++) {
      int check = 0;
      for (int j = 0; j < h - 1; j++) {
        if (grid.at(j).at(i) == '.' && grid.at(j + 1).at(i) == '.') check++;
      }
      if (check == h - 1) width.at(i) = false;
      else width.at(i) = true;
    }

    for (int i = 0; i < h; i++) {
      if (height.at(i) == true) {
        for (int j = 0; j < w; j++) {
          if (width.at(j) == true) {
            if (j != w - 1) cout << grid.at(i).at(j);
            else cout << grid.at(i).at(j) << endl;
          }
          else {
            if (j == w - 1) cout << endl;
          }
        }
      }
    }
  }
}
