#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  bool black = false;
  vector<vector<char>> a(H, vector<char>(W));
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cin >> a.at(i).at(j);
      if(a.at(i).at(j) == '#')
        black = true;
    }
    if(!black)
      for(int j = 0; j < W; j++)
        a.at(i).at(j) = '-';
    black = false;
  }
  for(int j = 0; j < W; j++) {
    for(int i = 0; i < H; i++) {
      if(a.at(i).at(j) == '#')
        black = true;
    }
    if(!black)
      for(int i = 0; i < H; i++)
        a.at(i).at(j) = '-';
    black = false;
  }
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(a.at(i).at(j) != '-') {
        cout << a.at(i).at(j);
        black = true;
      }
    }
    if(black) {
      cout << endl;
      black = false;
    }
  }
}