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
  
  vector<bool> f_line(H, false), f_column(W, false); 
  
  for (int i = 0; i < H; i++) {
    if (W == 1 && a.at(i).at(0) == '.') {
      f_line.at(i) = true;
      continue;
    }
    for (int j = 0; j < W-1; j++) {
      if (a.at(i).at(j) != a.at(i).at(j+1)) {
        break;
      }
      else if (a.at(i).at(j) == '.' && j == W-2) f_line.at(i) = true;
    }
  }
  
  for (int j = 0; j < W; j++) {
    if (H == 1 && a.at(0).at(j) == '.') {
      f_column.at(j) = true;
      continue;
    }
    for (int i = 0; i < H-1; i++) {
      if (a.at(i).at(j) != a.at(i+1).at(j)) {
        break;
      }
      else if (a.at(i).at(j) == '.' && i == H-2) f_column.at(j) = true;
    }
  }
  
  for (int i = 0; i < H; i++) {
    if (f_line.at(i) == true) continue;
      for (int j = 0; j < W; j++) {
        if (f_column.at(j) == true) continue;
        cout << a.at(i).at(j);
      }
    cout << endl;
  }
}