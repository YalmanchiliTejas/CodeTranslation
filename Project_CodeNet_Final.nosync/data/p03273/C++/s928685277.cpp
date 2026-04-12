#include <bits/stdc++.h>
using namespace std;

int main() {
  bool line, n;
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  for (int i = 0; i < H; i++)
    cin >> a.at(i);
  for (int i = 0; i < H; i++) {
    line = true;
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '#') {
        line = false;
        break;
      }
    }
    if (line) {
      for (int j = 0; j < W; j++) {
        a.at(i).at(j) = 'n';
      }
    }
  }
  for (int i = 0; i < W; i++) {
    line = true;
    for (int j = 0; j < H; j++) {
      if (a.at(j).at(i) == '#') {
        line = false;
        break;
      }
    }
    if (line) {
      for (int j = 0; j < H; j++) {
        a.at(j).at(i) = 'n';
      }
    }
  }
  for (int i = 0; i < H; i++) {
    n = false;
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) != 'n'){
        cout << a.at(i).at(j);
        n = true;
      }
    }
    if (n)
      cout << endl;
  }
}