#include <bits/stdc++.h>
using namespace std;

struct dat {
  int x, y;
  dat(int _x, int _y) : x(_x), y(_y) {}
  bool operator==(const dat& r) { return x == r.x && y == r.y; }
};

int d[4] = {0, 1, 0, -1};
int h, w;
vector<string> s;
queue<dat> qu;

bool isvalid(dat& now) {
  return now.x >= 0 && now.x < h && now.y >= 0 && now.y < w &&
         s[now.x][now.y] == '.';
}
bool solve();

int main() {
  while (1) {
    cin >> h >> w;
    if (h + w == 0) break;
    s.resize(h);
    for (int i = 0; i < h; ++i) cin >> s[i];
    if (solve())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

bool solve() {
  for (int x = 0; x < h; ++x)
    for (int y = 0; y < w; ++y) {
      dat ng = {x, y};
      vector<dat> v = {dat(0, 0), dat(h - 1, 0), dat(h - 1, w - 1),
                       dat(0, w - 1)};
      for (int t = 0; t < 4; ++t) {
        dat st = v[t], go = v[(t + 1) % 4];
        if (st == ng || go == ng) continue;
        vector<vector<bool>> reached(h, vector<bool>(w, 0));
        qu.push(st);
        reached[st.x][st.y] = 1;
        while (qu.size()) {
          dat now = qu.front();
          qu.pop();
          for (int i = 0; i < 4; ++i) {
            dat nextp = now;
            nextp.x += d[i];
            nextp.y += d[1 ^ i];
            if (!isvalid(nextp) || reached[nextp.x][nextp.y] || nextp == ng)
              continue;
            reached[nextp.x][nextp.y] = 1;
            qu.push(nextp);
          }
        }
        if (!reached[go.x][go.y]) return 0;
      }
    }
  return 1;
}
