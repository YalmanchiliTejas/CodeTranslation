#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int h, w;
  std::cin >> h >> w;
  std::vector<string> a(h);
  rep(i, h) { std::cin >> a[i]; }

  std::vector<int> v1(h), v2(w);

  rep(i, h) {
    rep(j, w) {
      if (a[i][j] == '#') {
        v1[i] = 1;
        break;
      }
    }
  }

  rep(i, w) {
    rep(j, h) {
      if (a[j][i] == '#') {
        v2[i] = 1;
        break;
      }
    }
  }

  rep(i, h) {
    bool ok = false;
    rep(j, w) {
      if (v1[i] == 1 && v2[j] == 1) {
        std::cout << a[i][j];
        ok = true;
      }
    }
    if (ok) {
      std::cout << std::endl;
    }
  }

  return 0;
}
