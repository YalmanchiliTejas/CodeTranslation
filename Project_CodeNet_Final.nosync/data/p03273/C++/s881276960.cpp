#include <bits/stdc++.h>
using namespace std;

bool ch[2][105] = {0};
char mp[105][105];
int h, w;

int main() {
  int i, j;
  cin >> h >> w;
  for(i = 0; i < h; ++i)
    for(j = 0; j < w; ++j) {
      cin >> mp[i][j];
      if(mp[i][j] == '#') ch[0][i] = ch[1][j] = 1;
    }
  for(i = 0; i < h; ++i) {
    for(j = 0; j < w; ++j)
      if(ch[0][i] && ch[1][j]) cout << mp[i][j];
    cout << endl;
  }
  return 0;
}