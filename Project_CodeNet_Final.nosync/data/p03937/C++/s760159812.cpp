#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for(int i = 0; i < h; i++) {
    cin >> s[i];
  }
  int c = 0;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(s[i][j] == '#') c++;
    }
  }
  if(c == h + w - 1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}