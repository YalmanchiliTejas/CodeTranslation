#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> grid(H);
  for (int i=0; i < H; i++) {
    cin >> grid.at(i);
  }
  vector<int> allow;
  for (int i=0; i < H; i++) {
    int dotc = 0;
    for (int j=0; j < W; j++) {
      if (grid.at(i).at(j) == '.') {
        dotc++;
      }
    }
    if (dotc != W) {
      allow.push_back(i);
    }
  }
  vector<string> grid2(allow.size());
  for (int i=0; i < allow.size(); i++) {
    grid2.at(i) = grid.at(allow.at(i));
  }
  vector<int> allow2;
  for (int i=0; i < W; i++) {
    int dotc = 0;
    for (int j=0; j < grid2.size(); j++) {
      if (grid2.at(j).at(i) == '.') {
        dotc++;
      }
    }
    if (dotc != grid2.size()) {
      allow2.push_back(i);
    }
  }
  vector<vector<char>> grid3(grid2.size(),vector<char>(allow2.size()));
  for (int i=0; i < grid2.size(); i++) {
    for (int j=0; j < allow2.size(); j++) {
      grid3.at(i).at(j) = grid2.at(i).at(allow2.at(j));
    }
  }
  for (int i=0; i < grid2.size(); i++) {
    for (int j=0; j < allow2.size(); j++) {
    cout << grid3.at(i).at(j);
      if (j == allow2.size() - 1) {
        cout << endl;
      }
    }
  }
}