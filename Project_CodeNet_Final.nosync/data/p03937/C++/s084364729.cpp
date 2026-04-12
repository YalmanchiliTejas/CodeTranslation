#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int dh[] = {1, 0, -1, 0};
const int dw[] = {0, 1, 0, -1};

void dfs(int h, int w, vector<string>& s, vector<vector<bool>>& v) {
  v[h][w] = true;

  int size_h = s.size(), size_w = s.front().size();
  int cnt = 0, hh, ww;
  rep(k, 4) {
    int nh = h + dh[k], nw = w + dw[k];
    if ((nh < 0 || size_h <= nh || nw < 0 || size_w <= nw) || v[nh][nw])
      continue;
    if (s[nh][nw] == '#') {
      if (k < 2)
        ++cnt, hh = nh, ww = nw;
      else
        return;
    }
  }
  if (cnt == 1)
    dfs(hh, ww, s, v);
}

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  string dummy = string(w - 1, '.');
  dummy.push_back('#');
  s.push_back(dummy);
  ++h;

  vector<vector<bool>> v(h, vector<bool>(w));
  dfs(0, 0, s, v);

  if (v[h - 1][w - 1])
    puts("Possible");
  else
    puts("Impossible");
}