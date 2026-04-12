#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int h, w;
  char s[10][10];
  cin >> h >> w;
  for (int i = 0; i < h; i++) cin >> s[i];
  
  int x = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w - 1; j++) {
      if (s[i][j] == '#' && s[i][j + 1] == '#')
        x++;
    }
  }
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h - 1; j++) {
      if (s[j][i] == '#' && s[j + 1][i] == '#')
        x++;
    }
  }
  
  if (x == h + w - 2) cout << "Possible\n";
  else cout << "Impossible\n";
  
  return 0;
}
    