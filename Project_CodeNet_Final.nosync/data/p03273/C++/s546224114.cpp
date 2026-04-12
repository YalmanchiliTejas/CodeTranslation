#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main () {
  int H, W;
  cin >> H >> W;
    
  unordered_set<int> only_white_col;
  unordered_set<int> only_white_row;
  bool only_white;
    
  char sq[H][W];
  for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
          cin >> sq[i][j];
      }
  }
  
  for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
          if (sq[i][j] != '.') {
              only_white = false;
              break;
          } else {
              only_white = true;
          }
      }
      if (only_white) {
          only_white_row.insert(i);
      }
  }
    
  for (int i = 0; i < W; ++i) {
      for (int j = 0; j < H; ++j) {
          if (sq[j][i] != '.') {
              only_white = false;
              break;
          } else {
              only_white = true;
          }
      }
      if (only_white) {
          only_white_col.insert(i);
      }
  }
    
  for (int i = 0; i < H; ++i) {
      if (only_white_row.count(i) != 0) {
          continue;
      }
      for (int j = 0; j < W; ++j) {
          if (only_white_col.count(j) != 0) {
              continue;
          }
          cout << sq[i][j];
      }
      cout << "\n";
  }
    
  return 0;
}