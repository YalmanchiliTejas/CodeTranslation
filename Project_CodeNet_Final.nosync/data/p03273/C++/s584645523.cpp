#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> col(H, vector<char>(W));
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      cin >> col.at(i).at(j);
  
  for (int i = 0; i < H; i++) {
    int del = 1;
    for (int j = 0; j < W; j++)
      if(col.at(i).at(j) == '#')
        del = 0;
    if(del)
      for (int j = 0; j < W; j++)
        col.at(i).at(j) = 'l';
  }
  
  for (int j = 0; j < W; j++) {
    int del = 1;
    for (int i = 0; i < H; i++)
      if(col.at(i).at(j) == '#')
        del = 0;
    if(del)
      for (int i = 0; i < H; i++)
        if(col.at(i).at(j) == '.')
          col.at(i).at(j) = 'x';
  }
  
  for (int i = 0; i < H; i++) {
    if(col.at(i).at(0) == 'l') continue;
    for (int j = 0; j < W; j++) {
      if(col.at(i).at(j) == '.' || col.at(i).at(j) == '#')
        cout << col.at(i).at(j);
    }
    cout << endl;
  }
}