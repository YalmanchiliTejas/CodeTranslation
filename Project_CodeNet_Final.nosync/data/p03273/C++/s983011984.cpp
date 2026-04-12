#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a.at(i).at(j);
    }
  }
  
  vector<bool> isWhiteRow(H, true);
  vector<bool> isWhiteColumn(W, true);
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '#') {
        isWhiteRow.at(i) = false;
        break;
      }
    }
  }
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      if (a.at(i).at(j) == '#') {
        isWhiteColumn.at(j) = false;
      }
    }
  }
/*  for (int i = 0; i < H; i++) {
    cout << "isWhiteRow.at(i) = " << isWhiteRow.at(i) << endl;
  }
  for (int j = 0; j < W; j++) {
    cout << "isWhiteColumn.at(j) = " << isWhiteColumn.at(j) << endl;
  }
*/  
  for (int i = 0; i < H; i++) {
    if (isWhiteRow.at(i)) continue;
    for (int j = 0; j < W; j++) {
      if (isWhiteColumn.at(j)) continue;
      cout << a.at(i).at(j);
    }  
    cout << endl;
  }   
}