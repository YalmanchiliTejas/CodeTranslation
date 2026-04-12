#include <bits/stdc++.h>
using namespace std;
int main() {
  int h,w;
  cin >> h >> w;
  vector<bool> x(w,false);
  vector<bool> y(h,false);
  vector<vector <char>> board(h,vector<char>(w));
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      cin >> board.at(i).at(j);
    }
  }
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (board.at(i).at(j) == '#') {
        y[i] = true;
        x[j] = true;
      }
    }
  }
  for (int i=0; i<h; i++) {
    if (y[i] == true) {
      for (int j=0; j<w; j++) {
        if (x[j] == true) {
          cout << board.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}