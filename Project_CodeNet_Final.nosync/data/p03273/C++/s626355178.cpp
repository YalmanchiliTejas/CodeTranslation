#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> data(H, vector<char>(W));
  
  for (int i = 0; i<H; i++) {
    for (int j = 0; j<W; j++) {
      cin >> data.at(i).at(j);
    }
  }
  
  for (int i = 0; i<H; i++) {
    bool empty = true;
    for (int j = 0; j<W; j++) {
      if (data.at(i).at(j) == '#') {
        empty = false;
        break;
      }
    }
    if (empty) {
      for (int j = 0; j<W; j++) {
        data.at(i).at(j) = 'e';
      }
    }
  }

  for (int j = 0; j<W; j++) {
    bool empty = true;
    for (int i = 0; i<H; i++) {
      if (data.at(i).at(j) == '#') {
        empty = false;
        break;
      }
    }
    if (empty) {
      for (int i = 0; i<H; i++) {
        data.at(i).at(j) = 'e';
      }
    }
  }

  for (int i = 0; i<H; i++) {
    bool empty = true;
    for (int j = 0; j<W; j++) {
      if (data.at(i).at(j) != 'e') {
        cout << data.at(i).at(j);
        empty = false;
      }
    }
    if (!empty) cout << endl;
  }
}

