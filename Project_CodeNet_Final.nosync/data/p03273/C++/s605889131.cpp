#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W, ' '));
  vector<vector<char>> ans(H, vector<char>(W, ' '));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a.at(i).at(j);
      ans.at(i).at(j) = a.at(i).at(j);
    }
  }

  vector<int> h_flag(W);
  vector<int> w_flag(H);

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '#') {
        w_flag.at(i) = 0;
        break;
      } else {
        w_flag.at(i)++;
      }
    }
  }

  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      if (a.at(i).at(j) == '#') {
        h_flag.at(j) = 0;
        break;
      } else {
        h_flag.at(j)++;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (w_flag.at(i) == W) {
        ans.at(i).at(j) = 'x';
      }
      if (h_flag.at(j) == H) {
        ans.at(i).at(j) = 'x';
      }
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (ans.at(i).at(j) != 'x') {
        cout << ans.at(i).at(j);
      }
    }
    if (w_flag.at(i) != W) {
      cout << endl;
    }
  }
}
