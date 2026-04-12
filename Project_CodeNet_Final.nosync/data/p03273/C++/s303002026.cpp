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
  
  bool flag;
  for (int i = 0; i < h; i++) {
    flag = true;
    for (int j = 0; j < w; j++) {
      if (board.at(i).at(j) == '#')
        flag = false;
    }
    if (flag) {
      for (int j = 0; j < w; j++) {
        board.at(i).at(j) = ' ';
      }
    }
  }
  
  for (int i = 0; i < w; i++) {
    flag = true;
    for (int j = 0; j < h; j++) {
      if (board.at(j).at(i) == '#')
        flag = false;
    }
    if (flag) {
      for (int j = 0; j < h; j++)
        board.at(j).at(i) = ' ';
    }
  }
  
  for (int i = 0; i < h; i++) {
    flag = false;
    for (int j = 0; j < w; j++) {
      if (board.at(i).at(j) != ' ') {
        cout << board.at(i).at(j);
        flag = true;
      }
    }
    if (flag)
      cout << endl;
  }
  
  return 0;
}
