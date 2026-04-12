#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int H,W;
  cin >> H >> W;
  char a[H][W];
  bool s[H];
  bool t[W];
  for (int i = 0; i < H; i++) s[i] = true;
  for (int j = 0; j < W; j++) t[j] = true;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
      if (a[i][j] == '#') {
        s[i] = false;
        t[j] = false;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    if (s[i]) {
      continue;
    }
    for (int j = 0; j < W; j++) {
      if (!t[j]) {
        cout << a[i][j];
      }
    }
    cout << endl;
  } 
  return 0;
}