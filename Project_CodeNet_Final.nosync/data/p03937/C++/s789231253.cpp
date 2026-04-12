#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int h, w;
  cin >> h >> w;
  int cnt = 0;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    for (int i = 0; i < w; i++) {
      if (s[i] == '#') {
        cnt++;
      }
    }
  }

  if (cnt == h + w - 1) {
    puts("Possible");
  } else {
    puts("Impossible");
  }

  return 0;
}
