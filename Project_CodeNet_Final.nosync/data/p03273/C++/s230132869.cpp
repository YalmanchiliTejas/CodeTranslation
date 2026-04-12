#include <bits/stdc++.h>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<string> map(H);
  vector<string> tsp(W, "");
  
  // template for all dots.
  string dots = ".";
  for (int i=1; i < W; i++)
    dots += '.';
  // transposed template.
  string tspdots = ".";
  for (int i=1; i < H; i++)
    tspdots += '.';

  for (int i=0; i < H; i++) {
    cin >> map.at(i);
    for (int j=0; j < W; j++) {
      tsp.at(j) += map.at(i).at(j);
    }
  }
  
  vector<int> remain_row;
  vector<int> remain_col;
  for (int i=0; i < H; i++) {
    if (map.at(i) == dots)
      continue;
    remain_row.push_back(i);
  }
  
  for (int i=0; i < W; i++) {
    if (tsp.at(i) == tspdots)
      continue;
    remain_col.push_back(i);
  }
  
  for (int i : remain_row) {
    for (int j : remain_col) {
      cout << map.at(i).at(j);
    }
    cout << endl;
  }
}