#include <bits/stdc++.h>
using namespace std;

const int MAXN = 51;
const int H = 222;
const int W = 222;
const int di[] = {0,1,0,-1};
const int dj[] = {1,0,-1,0};
int n;
int l[MAXN], t[MAXN], r[MAXN], b[MAXN];
vector<int> xs, ys;
int G[H][W];

void dfs(int i, int j) {
  G[i][j] = 1;
  for(int k = 0; k < 4; ++k) {
    int ni = i + di[k];
    int nj = j + dj[k];
    if(ni < 0 || ni >= H) continue;
    if(nj < 0 || nj >= W) continue;
    if(G[ni][nj]) continue;
    dfs(ni, nj);
  }
}

int main() {
  while(cin >> n && n) {
    xs.clear();
    ys.clear();
    for(int i = 0; i < n; ++i) {
      cin >> l[i] >> t[i] >> r[i] >> b[i];
      xs.push_back(l[i]);
      xs.push_back(r[i]);
      ys.push_back(t[i]);
      ys.push_back(b[i]);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    for(int i = 0; i < n; ++i) {
      l[i] = lower_bound(xs.begin(), xs.end(), l[i]) - xs.begin();
      r[i] = lower_bound(xs.begin(), xs.end(), r[i]) - xs.begin();
      t[i] = lower_bound(ys.begin(), ys.end(), t[i]) - ys.begin();
      b[i] = lower_bound(ys.begin(), ys.end(), b[i]) - ys.begin();
      l[i] = l[i] * 2 + 1;
      r[i] = r[i] * 2 + 1;
      t[i] = t[i] * 2 + 1;
      b[i] = b[i] * 2 + 1;
    }
    memset(G, 0, sizeof(G));
    for(int i = 0; i < n; ++i) {
      for(int x = l[i]; x <= r[i]; ++x) {
        G[t[i]][x] = G[b[i]][x] = 1;
      }
      for(int y = b[i]; y <= t[i]; ++y) {
        G[y][l[i]] = G[y][r[i]] = 1;
      }
    }
    int res = 0;
    for(int i = 0; i < H; ++i) {
      for(int j = 0; j < W; ++j) {
        if(G[i][j]) continue;
        dfs(i, j);
        res += 1;
      }
    }
    cout << res << endl;
  }
  return 0;
}