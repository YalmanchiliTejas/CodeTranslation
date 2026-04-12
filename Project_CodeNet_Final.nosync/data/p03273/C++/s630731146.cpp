#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> table(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> table.at(i).at(j);
    }
  }

  vector<bool> A(H, true);
  int a = 0;
  for (int i = 0; i < H; i++) {
    int x = 0;
    for (int j = 0; j < W; j++) {
      if (table.at(i).at(j) == '#') x++;
    }
    if (x == 0) {
      A.at(i) = false;
      a++;
    }
  }

  vector<bool> B(W,true);
  int b = 0;
  for (int i = 0; i < W; i++) {
    int x = 0;
    for (int j = 0; j < H; j++) {
      if (table.at(j).at(i) == '#') x++;
    }
    if (x == 0) {
      B.at(i) = false;
      b++;
    }
  }

  int c = 0;
  vector<vector<char>> ans(H);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (A.at(i) && B.at(j)) {
        ans.at(c).push_back(table.at(i).at(j));
      }
    }
    if (ans.at(c).size() != 0) c++;
  }

  for (int i = 0; i < H - a; i++) {
    for (int j = 0; j < W - b; j++) {
      cout << ans.at(i).at(j);
    }
    cout << endl;
  }
}
