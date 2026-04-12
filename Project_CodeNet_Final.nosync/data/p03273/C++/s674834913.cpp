#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int H, W;
string s[110];
int a[110], b[110];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < H; i++) {
    int all = 1;
    for (int j = 0; j < W; j++) {
      if (s[i][j] == '#') all = 0;
    }
    a[i] = all;
  }
  for (int j = 0; j < W; j++) {
    int all = 1;
    for (int i = 0; i < H; i++) {
      if (s[i][j] == '#') all = 0;
    }
    b[j] = all;
  }
  for (int i = 0; i < H; i++) {
    if (a[i]) continue;
    for (int j = 0; j < W; j++) {
      if (b[j]) continue;
      cout << s[i][j];
    }
    cout << endl;
  }

  return 0;
}