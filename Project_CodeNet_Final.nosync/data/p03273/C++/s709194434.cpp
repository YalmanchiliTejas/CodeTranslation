#include <bits/stdc++.h>
using namespace std;

int H = 0;
int W = 0;
string str[120];

void solve() {
  bool ignH[120] = {0};
  bool ignW[120] = {0};
  set<char> s;
  for (int i = 0; i < H; i++) {
    s.clear();
    for (int j = 0; j < W; j++) {
      s.insert(str[i][j]);
    }
    if (s.size() == 1 && s.find('.') != s.end()) {
      ignH[i] = true;
    }
  }
  for (int j = 0; j < W; j++) {
    s.clear();
    for (int i = 0; i < H; i++) {
      s.insert(str[i][j]);
    }
    if (s.size() == 1 && s.find('.') != s.end()) {
      ignW[j] = true;
    }
  }
  for (int i = 0; i < H; i++) {
    if (ignH[i] == true) continue;
    for (int j = 0; j < W; j++) {
      if (ignW[j] == true) continue;
      printf("%c", str[i][j]);
    }
    puts("");
  }
}

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    cin >> str[i];
  }
  solve();
  return 0;
}
