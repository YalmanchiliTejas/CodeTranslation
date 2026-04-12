#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> a(H);
  for (int i = 0; i < H; i++) {
    cin >> a.at(i);
  }

  vector<bool> row(H);
  vector<bool> col(W);

  for (int i = 0; i < H; i++) {
    row.at(i) = false;
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '#') row.at(i) = true;
    }
  }

  for (int j = 0; j < W; j++) {
    col.at(j) = false;
    for (int i = 0; i < H; i++) {
      if (a.at(i).at(j) == '#') col.at(j) = true;
    }
  }

  for (int i = 0; i < H; i++) {
    bool output = false;
    for (int j = 0; j < W; j++) {
      if (row.at(i) && col.at(j)) {
        cout << a.at(i).at(j);
        output = true;
      }
    }
    if (output) cout << endl;
  }
}
