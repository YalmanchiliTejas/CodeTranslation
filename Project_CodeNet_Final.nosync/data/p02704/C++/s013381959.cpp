#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

vector<vector<ull>> a;
bool ng = false;

ull f(ull s, ull t, ull u, ull v) {
  if (u == 0 && v == 0) return 0;
  if (u == 1 && v == 1) return 1;
  if (s == 1 && t == 1) return 0;
  if (s == 0 && t == 0) return 1;
  if (s * u + t * v == 0) ng = true;
  return 0;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  a.assign(n, vector<ull>(n, 0));
  
  vector<ull> s(n), t(n), u(n), v(n);
  for (int i = 0; i < n; i++) cin >> s.at(i);
  for (int i = 0; i < n; i++) cin >> t.at(i);
  for (int i = 0; i < n; i++) cin >> u.at(i);
  for (int i = 0; i < n; i++) cin >> v.at(i);
  
  for (int k = 0; k < 64; k++) { // k-th bit
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ull tmp = f(s[i], t[j], ((u[i] >> k) & 1ULL), ((v[j] >> k) & 1ULL));
        a[i][j] |= ((ull) tmp << k);
      }
    }
  }
  
  if (ng) {
    cout << -1 << '\n';
    return 0;
  }
  
  vector<vector<ull>> versum(64, vector<ull>(n, 0)), horsum(64, vector<ull>(n, 0)); // versum[k][j]: popcount k-th bit from a[0][j] to a[n-1][j]
  for (int k = 0; k < 64; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] & (1ULL << k)) {
          versum[k][j]++;
          horsum[k][i]++;
        }
      }
    }
  }
  
  for (int k = 0; k < 64; k++) {
    for (int i = 0; i < n; i++) {
      if (s[i] == 1 && (u[i] & (1ULL << k))) { // row of bitsum = 1
        ull keep = 0;
        for (int j = 0; j < n; j++) {
          keep |= (a[i][j] & (1ULL << k));
        }
        if (keep) continue;
        for (int j = 0; j < n; j++) {
          if (t[j] == 0 && !(v[j] & (1ULL << k))) {
            if (versum[k][j] < n - 1) {
              a[i][j] |= (1ULL << k);
              horsum[k][i]++;
              versum[k][j]++;
              break;
            }
          }
        }
      }
    }
  }
  
  for (int k = 0; k < 64; k++) {
    for (int j = 0; j < n; j++) {
      if (t[j] == 1 && (v[j] & (1ULL << k))) { // column of bitsum = 1
        ull keep = 0;
        for (int i = 0; i < n; i++) {
          keep |= (a[i][j] & (1ULL << k));
        }
        if (keep) continue;
        for (int i = 0; i < n; i++) {
          if (s[i] == 0 && !(u[i] & (1ULL << k))) {
            if (horsum[k][i] < n - 1) {
              a[i][j] |= (1ULL << k);
              horsum[k][i]++;
              versum[k][j]++;
              break;
            }
          }
        }
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    ull keep;
    if (s[i] == 0) keep = ~0;
    else keep = 0;
    for (int j = 0; j < n; j++) {
      if (s[i] == 0) keep &= a[i][j];
      else keep |= a[i][j];
    }
    if (keep != u[i]) ng = true;
  }
  for (int j = 0; j < n; j++) {
    ull keep;
    if (t[j] == 0) keep = ~0;
    else keep = 0;
    for (int i = 0; i < n; i++) {
      if (t[j] == 0) keep &= a[i][j];
      else keep |= a[i][j];
    }
    if (keep != v[j]) ng = true;
  }
  
  if (ng) {
    cout << -1 << '\n';
    return 0;
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j) cout << " ";
      cout << a[i][j];
    }
    cout << '\n';
  }
}