#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;

  cin >> H >> W;

  vector<string> a(H);

  for (int i = 0; i < H; i++) {
    cin >> a.at(i);
  }

  for (int i = 0; i < H; i++) {
    int j = 0;
    while (j < W && (a.at(i).at(j) == '.' || a.at(i).at(j) == ' ')) {
      j++;
    }
    if (j == W) {
      for (int j = 0; j < W; j++) {
        a.at(i).at(j) = ' ';
      }
    }
  }

  for (int i = 0; i < W; i++) {
    int j = 0;
    while (j < H && (a.at(j).at(i) == '.' || a.at(j).at(i) == ' ')) {
      j++;
    }
    if (j == H) {
      for (int j = 0; j < H; j++) {
        a.at(j).at(i) = ' ';
      }
    }
  }

  for (int i = 0; i < H; i++) {
    int replacedCount = 0;
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) != ' ') {
        cout << a.at(i).at(j);
      } else {
        replacedCount++;
      }
    }
    if (replacedCount < W) {
      cout << endl;
    }
  }
}
