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
  
  int countH = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '#') {
        break;
      }
      if (j == W-1) {
        countH++;
      }
    }
  }

  vector<vector<char>> h(H-countH,vector<char>(W));
  int x=0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '#') {
        h.at(i-x) = a.at(i);
        break;
      }
      if (j == W-1) {
        x++;
      }
    }
  }
     
  
  int countW = 0;
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      if (a.at(i).at(j) == '#') {
        break;
      }
      if (i == H-1) {
        countW++;
      }
    }
  }
   
  vector<vector<char>> ans(H-countH,vector<char>(W-countW,'.'));
  int c;
  x=0;
  for (int j = 0; j < W; j++) {
    c=0;
    for (int i = 0; i < H-countH; i++) {
      if (h.at(i).at(j) == '#') {
        ans.at(i).at(j-x) = '#';
        c++;
      }
      if (i==H-countH-1 && c==0 && h.at(i).at(j) == '.') {
        x++;
      }
    }
  }
  
  for (int i = 0; i < H-countH; i++) {
    for (int j = 0; j < W-countW; j++) {
      cout << ans.at(i).at(j);
    }
    cout << endl;
  }
}