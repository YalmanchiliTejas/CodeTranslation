#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> vs;
  int skip_row_cnt = 0;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    if (s.find('#') != string::npos) {
      vs.push_back(s);
    } else {
      skip_row_cnt++;
    }
  }
  int skip_column[w];
  for (int i = 0; i < w; i++) {
    skip_column[i] = 0;
  }
  for (int i = 0; i < w; i++) {
    bool dot_only = true;
    for (int j = 0; j < h - skip_row_cnt; j++) {
      if (vs[j][i] == '#') {
        dot_only = false;
        break;
      }
    }
    if (dot_only) {
      skip_column[i] = 1;
    }
  }

  for (int i = 0; i < h - skip_row_cnt; i++) {
    for (int j = 0; j < w; j++) {
      if (skip_column[j]) continue;
      cout << vs[i][j];
    }
    cout << '\n';
  }
}