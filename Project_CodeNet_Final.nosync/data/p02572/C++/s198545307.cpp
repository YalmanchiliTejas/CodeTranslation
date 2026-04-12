#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)

int main() {
  int n;
  cin >> n;
  __int128 s2 = 0;
  __int128 diag2 = 0;
  __int128 mod = 1e9 + 7;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    __int128 ai = a;
    s2 += ai;
    diag2 += ai * ai;
  }
  s2 *= s2;
  __int128 ret = (s2 - diag2) / 2;
  ret %= mod;
  cout << (int)ret << endl;
  return 0;
}
