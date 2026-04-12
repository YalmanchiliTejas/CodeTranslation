#include <bits/stdc++.h>
using namespace std;

long long n;
vector<vector<unsigned long long>> res;
vector<long long> s, t;
vector<unsigned long long> u, v;

bool solve();

int main() {
  cin >> n;
  s.resize(n);
  t.resize(n);
  u.resize(n);
  v.resize(n);
  res.assign(n, vector<unsigned long long>(n, 0));
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 0; i < n; ++i) cin >> t[i];
  for (int i = 0; i < n; ++i) cin >> u[i];
  for (int i = 0; i < n; ++i) cin >> v[i];
  if (solve()) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j != 0) cout << " ";
        cout << res[i][j];
      }
      cout << endl;
    }
  } else
    cout << -1 << endl;
  return 0;
}

bool solve() {
  for (long long B = 0; B < 64; ++B) {
    vector<vector<long long>> tmp(n, vector<long long>(n, -1));
    vector<long long> r(n, 0), c(n, 0);
    for (int i = 0; i < n; ++i)
      if (s[i] != (u[i] >> B & 1)) {
        r[i] = 1;
        for (int j = 0; j < n; ++j) tmp[i][j] = (u[i] >> B & 1);
      }
    for (int j = 0; j < n; ++j)
      if (t[j] != (v[j] >> B & 1)) {
        c[j] = 1;
        for (int i = 0; i < n; ++i) {
          if (tmp[i][j] == 1 - (long long)(v[j] >> B & 1)) return 0;
          tmp[i][j] = (v[j] >> B & 1);
        }
      }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (s[i] == tmp[i][j]) r[i] = 1;
        if (t[j] == tmp[i][j]) c[j] = 1;
      }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (r[i] + c[j] == 0 && s[i] == t[j] && tmp[i][j] < 0) {
          r[i] = c[j] = 1;
          tmp[i][j] = s[i];
        }

    while (1) {
      bool ch = 0;
      while (1) {
        ch = 0;
        for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j) {
            if (r[i] ^ c[j] && tmp[i][j] < 0) {
              if (!r[i]) {
                tmp[i][j] = s[i];
                r[i] = 1;
                ch = 1;
              } else {
                tmp[i][j] = t[j];
                c[j] = 1;
                ch = 1;
              }
            }
          }
        if (!ch) break;
      }
      ch = 0;
      for (int i = 0; i < n && !ch; ++i)
        for (int j = 0; j < n && !ch; ++j)
          if (tmp[i][j] < 0 && (r[i] + c[j] != 2)) {
            ch = 1;
            tmp[i][j] = s[i];
            r[i] = 1;
          }
      if (!ch) break;
    }
    for (int i = 0; i < n; ++i)
      if (r[i] + c[i] != 2) return 0;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (tmp[i][j] == 1) res[i][j] += 1ULL << B;
  }
  return 1;
}