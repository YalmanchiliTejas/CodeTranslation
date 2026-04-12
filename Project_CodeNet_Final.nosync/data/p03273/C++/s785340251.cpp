#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> vec(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> vec.at(i).at(j);
    }
  }
  vector<bool> row(h, 0);
  vector<bool> col(w, 0);

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (vec.at(i).at(j) == '#') {
        row.at(i) = 1;
        break;
      }
    }
  }

  for (int j = 0; j < w; j++) {
    for (int i = 0; i < h; i++) {
      if (vec.at(i).at(j) == '#') {
        col.at(j) = 1;
        break;
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (row.at(i) and col.at(j)) {
        cout << vec.at(i).at(j);
      }
    }
      if (row.at(i)) {
      cout << endl;
    }
  }
}
