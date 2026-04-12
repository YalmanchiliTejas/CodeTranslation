#include <bits/stdc++.h>
using namespace std;

int main() {

  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  vector<bool>unspace(H, true);

  // 入力 (2重ループを用いる)
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> data.at(i).at(j);
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {

      // 上からi番目、左からj番目
      if (data.at(i).at(j) == '#') {
        break;
      }
      else if(j==W-1) {
        unspace.at(i) = false;
        for (int k = 0; k < W; k++) 
           data.at(i).at(k)='o';
      }

    }
  }

  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
       if (data.at(i).at(j) == '#') {
        break;
      }
      else if(i==H-1) {
        for (int m = 0; m < H; m++) 
           data.at(m).at(j)='o';
      }

    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (data.at(i).at(j) == 'o') {
        continue;
      }
      else {
        cout << data.at(i).at(j) ;
      }
    }
    if(unspace.at(i))
      cout << endl;
  }

}