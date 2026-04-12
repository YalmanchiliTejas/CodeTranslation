#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid(h, vector<char>(w));
  int x;
  for (int i = 0; i < h; i++) {
    x = 1;
    for (int j = 0; j < w; j++) {
      cin >> grid.at(i).at(j);
      if (grid.at(i).at(j) == '#') x = 0;
    }
    if (x == 1) {
      grid.pop_back();
      i--;
      h--;
    }
  }
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (grid.at(j).at(i) == '#') break;
      if (j == h - 1) {
        for (int k = 0; k < h; k++)
          grid.at(k).erase(grid.at(k).begin() + i);
        w--;
        i--;
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) cout << grid.at(i).at(j);
    cout << endl;
  }
}