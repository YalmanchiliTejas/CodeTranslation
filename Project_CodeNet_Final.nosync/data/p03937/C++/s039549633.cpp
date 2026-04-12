#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  int c = 0;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < w; j++) {
      if (s[j] == '#') {
        c++;
      }
    }
  }
  cout << (c == h + w - 1 ? "Possible" : "Impossible") << endl;
}
