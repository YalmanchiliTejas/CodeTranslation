#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  
  //二次元配列を宣言
  vector<vector<char>> table(H,vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> table.at(i).at(j);
    }
  }
  
  //p 残したい行の番号を記録
  vector<int> p;
  //q 残したい列の番号を記録
  vector<int> q;
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (table.at(i).at(j) == '#') {
        p.push_back(i);
        break;
      }
    }
  }
  
   for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      if (table.at(j).at(i) == '#') {
        q.push_back(i);
        break;
      }
    }
  }
  
  for (int i = 0; i < p.size(); i++) {
    for (int j = 0; j < q.size(); j++) {
      cout << table.at(p.at(i)).at(q.at(j));
      if ( j + 1 == q.size()) {
        cout << endl;
      }
    }
  }
}