#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int h, w;
  cin >> h >> w;

  vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }

  int cnt = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#') {
        cnt++;
      }
    }
  }

  if (cnt == h + w - 1) {
    cout << "Possible\n";
  } else {
    cout << "Impossible\n";
  }

  return 0;
}