#include <bits/stdc++.h>
#define inf (int)40000
using namespace std;

using P = pair<int, int>;
int n, last, ndp = 0;
vector<vector<int>> a, tdp, tmemo;
vector<int> ddp, odp, cnt;

int solve();

int main() {
  cin >> n;
  ddp.assign(n, -inf);
  tdp.assign(n, vector<int>(n, -inf));
  tmemo.assign(n, vector<int>(n, 0));
  odp.assign(n, -inf);
  cnt.assign(n, 0);
  {
    int x, y;
    cin >> x >> y;
    --x, --y;
    if (x > y) swap(x, y);
    if (x == y) ddp[x] = 0;
    odp[x] = odp[y] = 0;
    tdp[x][y] = 0;
  }
  a.resize(n - 1, vector<int>(3, 0));
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> a[i][j];
      --a[i][j];
    }
    sort(a[i].begin(), a[i].end());
    cnt[i + 1] = cnt[i] + (a[i][0] == a[i][2]);
  }
  cin >> last;
  --last;
  cout << solve() << endl;
  return 0;
}

int solve() {
  --n;
  for (int i = 0; i < n; ++i) {
    int nxtn = ndp;
    vector<pair<P, int>> nxtt;
    vector<int> nxtd = ddp, nxto = odp;
    // double
    for (int j = 0; j < 3; ++j) {
      int val = a[i][j];
      int now = ddp[val] + 1;
      vector<int> v;
      for (int k = 0; k < 3; ++k)
        if (j != k) v.push_back(a[i][k]);
      sort(v.begin(), v.end());
      nxtn = max(now, nxtn);
      for (auto p : v) nxto[p] = max(nxto[p], now);
      if (v[0] == v[1])
        nxtd[v[0]] = max(nxtd[v[0]], now);
      else
        nxtt.emplace_back(P(v[0], v[1]), now);
    }

    // t and o
    for (int j = 0; j < 2; ++j)
      if (a[i][j] == a[i][j + 1]) {
        int val = a[i][j];
        // t
        for (int k = 0; k <= n; ++k)
          if (k != val) {
            int x = val, y = k, now;
            if (x > y) swap(x, y);
            tdp[x][y] += cnt[i] - cnt[tmemo[x][y]];
            tmemo[x][y] = i;
            now = tdp[x][y] + 1;
            nxto[k] = max(nxto[k], now);
            P np(min(k, a[i][(j + 2) % 3]), max(k, a[i][(j + 2) % 3]));
            if (np.first == np.second)
              nxtd[np.first] = max(nxtd[np.first], now);
            else
              nxtt.emplace_back(np, now);
          }
        // o
        int now = odp[val] + 1;
        nxtn = max(nxtn, now);
        nxto[a[i][(j + 2) % 3]] = max(nxto[a[i][(j + 2) % 3]], now);
      }

    // n
    for (int j = 0; j < 3; ++j) {
      int x = a[i][j];
      nxto[x] = max(nxto[x], ndp);
      for (int k = j + 1; k < 3; ++k) {
        int y = a[i][k];
        if (x == y)
          nxtd[x] = max(nxtd[x], ndp);
        else
          nxtt.emplace_back(P(x, y), ndp);
      }

      for (int k = 0; k <= n; ++k) {
        int y = k, z = x, val = odp[k];
        if (y > z) swap(y, z);
        if (y == z)
          nxtd[y] = max(nxtd[y], val);
        else
          nxtt.emplace_back(P(y, z), val);
      }
    }

    // update
    ndp = max(nxtn, ndp + (int)(a[i][0] == a[i][2]));
    for (int j = 0; j <= n; ++j) {
      ddp[j] = max(nxtd[j], ddp[j] + (a[i][0] == a[i][2]));
      odp[j] = max(nxto[j], odp[j] + (a[i][0] == a[i][2]));
    }
    for (auto p : nxtt) {
      int x = p.first.first, y = p.first.second;
      if (tmemo[x][y] != i + 1)
        tdp[x][y] += cnt[i] - cnt[tmemo[x][y]] + (a[i][0] == a[i][2]);
      tmemo[x][y] = i + 1;
      tdp[x][y] = max(tdp[x][y], p.second);
    }
  }
  int res = ndp;
  for (int i = 0; i <= n; ++i) {
    res = max(res, odp[i]);
    res = max(res, ddp[i] + (last == i));
  }
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j) {
      tdp[i][j] += cnt[n] - cnt[tmemo[i][j]];
      res = max(res, tdp[i][j]);
    }
  return res;
}