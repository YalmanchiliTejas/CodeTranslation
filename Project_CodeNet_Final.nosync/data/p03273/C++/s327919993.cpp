#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> vec(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> vec.at(i).at(j);
    }
  }
  vector<int> num_sharp_in_row(H);
  vector<int> num_sharp_in_column(W);
  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < vec.at(0).size(); j++) {
      if (vec.at(i).at(j) == '#') {
        num_sharp_in_row.at(i)++;
        num_sharp_in_column.at(j)++;
      }
    }
  }

  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < vec.at(0).size(); j++){
      if (num_sharp_in_row.at(i) == 0 || num_sharp_in_column.at(j) == 0){
        continue;
      }
      cout << vec.at(i).at(j);
    }
    cout << endl;
  }
}