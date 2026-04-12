#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int fast_pow(int x, int y, int z = mod) {
  long long ret = 1;
  for (; y; y >>= 1, x = (long long)x * x % z) {
    if (y & 1)
      ret = ret * x % z;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  map<int, map<int, long long>> f;
  set<int> se;
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    se.insert(a[i]);
  }
  for (auto x : se) {
    if (x <= a[0]) {
      f[0][x] = fast_pow(2, a[0] - x + 1);
    }
  }
  f[0][0] = fast_pow(2, a[0]);
  se.insert(0);
  for (int i = 1; i < n; i++) {
    for (auto x : se) {
      if (x <= a[i]) {
        if (x > a[i - 1]) {
          f[i][x] = f[i - 1][a[i - 1]] * fast_pow(2, a[i] - x + 1) % mod;
        } else {
          if (a[i] > a[i - 1]) {
            f[i][x] = (f[i - 1][x] + f[i - 1][a[i - 1]]) * fast_pow(2, a[i] - a[i - 1]) % mod;
          } else {
            f[i][x] = (f[i - 1][x] + f[i - 1][a[i]]) % mod;
          }
        }
      }
    }
  }
  cout << f[n - 1][0] << endl;
  return 0;
}
