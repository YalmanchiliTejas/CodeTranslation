#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> arr(H, vector<char>(W));
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> arr.at(i).at(j);
    }
  }
  
  for (int i = 0; i < H; ++i) {
    
    bool isEmpty = true;
    for (int j = 0; j < W; ++j) {
      if (arr.at(i).at(j) == '#') isEmpty = false;
    }
    if (isEmpty) {
      for (int j = 0; j < W; ++j) {
        arr.at(i).at(j) = ' ';
      }
    }
  }
  for (int j = 0; j < W; ++j) {
    
    bool isEmpty = true;
    for (int i = 0; i < H; ++i) {
      if (arr.at(i).at(j) == '#') isEmpty = false;
    }
    if (isEmpty) {
      for (int i = 0; i < H; ++i) {
        arr.at(i).at(j) = ' ';
      }
    }
  }
  
  for (int i = 0; i < H; ++i) {
    bool isEmptyColumn = true;
    for (int j = 0; j < W; ++j) {
      bool isEmpty = false;
      if (arr.at(i).at(j) == ' ') {
        isEmpty = true;
        isEmptyColumn = isEmptyColumn && true;
      } else {
        isEmptyColumn = isEmptyColumn && false;
      }
      if (!isEmpty) cout << arr.at(i).at(j);
    }
    if (!isEmptyColumn) cout << endl;
  }
}
