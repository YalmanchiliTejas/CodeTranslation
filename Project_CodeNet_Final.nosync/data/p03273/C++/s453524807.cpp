#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  for (int h = 0; h < H; h++)
    for (int w = 0; w < W; w++)
      cin >> A[h][w];
  
  vector<vector<char>> tmp(H, vector<char>(W, '-'));
  vector<vector<char>> ans(H, vector<char>(W, '-'));
  

  int row = 0;
  for (vector<char> a : A) {
    bool all_yes = true;
    for (char c : a)
      if (c != '.') all_yes = false;
    if (!all_yes){
      tmp.at(row) = a;
      row++;
    }
  }

  int col = 0;
  for (int w = 0; w < W; w++) {
    bool all_yes = true;
    for (int h = 0; h < H; h++){
      if (tmp.at(h).at(w) == '#') all_yes = false;
    }
    if (!all_yes){
      for (int h = 0; h < H; h++)
        ans.at(h).at(col) = tmp.at(h).at(w);
      col++;
    }
  }
    
  for (vector<char> a : ans){
    for (char c : a)
      if (c != '-') cout << c;
    cout << endl;
  }
}
