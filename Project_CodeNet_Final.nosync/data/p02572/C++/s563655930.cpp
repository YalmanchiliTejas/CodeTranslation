#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef  int64_t llong;
llong mod(llong a, llong b) {
  llong res = a % b;
  if (res < 0) {
    return res + b;
  } else {
    return res;
  }
}

      



int main() {
  int n;
  cin >> n;
  vector<llong> a(n);
  for (int j = 0; j < n; ++j) cin >> a[j];

  llong s1 = 0;
  llong s2 = 0;
  llong modul = 1000'000'000 + 7;

  for (int j = 0; j < n; ++j) {
    s1 = mod(s1 + a[j], modul);
    s2 = mod(s2 + mod(a[j]*a[j], modul), modul);
  }

  llong ans = mod(s1*s1, modul);
  ans = mod(ans - s2, modul);
  llong half = (modul + 1) / 2;
  ans = mod(ans*half, modul);
  cout << ans << endl;
  
}
