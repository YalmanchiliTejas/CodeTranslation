#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int h, w;
  cin >> h >> w;

  vector<string> va(h);
  vector<bool> vr(h, false), vc(w, false);
  for (int i = 0; i < h; ++i) {
    cin >> va[i];
  }

  for (int i = 0; i < h; ++i) {
    bool skip = true;
    for (int j = 0; j < w; ++j) {
      if (va[i][j] == '#') {
        skip = false;
        break;
      }
    }

    vr[i] = skip;
  }

  for (int i = 0; i < w; ++i) {
    bool skip = true;
    for (int j = 0; j < h; ++j) {
      if (va[j][i] == '#') {
        skip = false;
        break;
      }
    }

    vc[i] = skip;
  }

  for (int i = 0; i < h; ++i) {
    if (vr[i]) {
      continue;
    }

    for (int j = 0; j < w; ++j) {
      if (!vc[j]) {
        cout << va[i][j];
      }
    }

    cout << '\n';
  }
  return 0;
}