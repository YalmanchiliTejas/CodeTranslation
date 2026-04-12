/**
 *    author:  tourist
 *    created: 13.01.2020 23:27:53       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  int cnt = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cnt += (s[i][j] == '#');
    }
  }
  cout << (cnt == h + w - 1 ? "Possible" : "Impossible") << '\n';
  return 0;
}
