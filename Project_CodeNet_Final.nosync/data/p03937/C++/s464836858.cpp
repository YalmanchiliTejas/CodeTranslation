#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  bool cant = false;
  for (int i = 0; i < h - 1; i++) {
    for (int j = 0; j < w - 1; j++) {
      cant |= (s[i + 1][j] == '#' && s[i][j + 1] == '#');
    }
  }
  cout << (cant ? "Impossible" : "Possible") << endl;

  return 0;
}