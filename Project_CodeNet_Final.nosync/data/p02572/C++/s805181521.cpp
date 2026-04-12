#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using int64 = int64_t;
using int128 = __int128_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int mod = (int)1e9 + 7;
  int n;
  cin >> n;
  int128 s = 0, s2 = 0;
  rep(i, n) {
    int64 a;
    cin >> a;
    s += a;
    s2 += a * a;
  }
  s *= s;
  cout << (int)((s - s2) / 2 % mod);
  return 0;
}