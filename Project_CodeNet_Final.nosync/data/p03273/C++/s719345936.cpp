#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  
  vector<vector<char>> board(h, vector<char> (w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++)
      cin >> board.at(i).at(j);
  }
  
  vector<bool> row(h, false);
  vector<bool> col(w, false);
  
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (board.at(i).at(j) == '#') {
        row.at(i) = true;
        col.at(j) = true;
      }
    }
  }
  
  for (int i = 0; i < h; i++) {
    if (row.at(i)) {
      for (int j = 0; j < w; j++) {
        if (col.at(j))
          cout << board.at(i).at(j);
      }
      cout << endl;
    }
  }
  
  return 0;
}
