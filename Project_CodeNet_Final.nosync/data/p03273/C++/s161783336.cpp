#include <bits/stdc++.h>
using namespace std;

int main() {
  int i, j;
  int h, w;
  cin >> h >> w;
  vector<vector<char>> board(h, vector<char>(w));
  for(i=0; i<h; i++) {
    for(j=0; j<w; j++) {
      cin >> board.at(i).at(j);
    }
  }
  
  vector<bool> cutH(h, false);
  vector<bool> cutW(w, false);
  for(i=0; i<h; i++) {
    if(board.at(i).at(0) == '.') {
      for(j=0; j<w; j++) {
        if(board.at(i).at(j) == '#')
          break;
      }
      if(j==w)
        cutH.at(i) = true;
    }
  }
  for(j=0; j<w; j++) {
    if(board.at(0).at(j) == '.') {
      for(i=0; i<h; i++) {
        if(board.at(i).at(j) == '#')
          break;
      }
      if(i==h)
        cutW.at(j) = true;
    }
  }
  
  for(i=0; i<h; i++) {
    if(!cutH.at(i)) {
      for (j=0; j<w; j++) {
        if(!cutW.at(j))
          cout << board.at(i).at(j);
      }
      cout << endl;
    }
  }
}