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
  for (int i = 0; i < n; ++i) cin >> a[i];

  llong s1 = 0;
  llong s2 = 0;
  llong modulus = 1000'000'000 + 7;
  for (int i = 0; i < n; ++i) {
    s1 = mod(s1 + a[i], modulus);
    s2 = mod(s2 + mod(a[i]*a[i], modulus), modulus);
  }

  llong ans = mod(s1*s1, modulus);
  ans = mod(ans - s2, modulus);

  llong half = (modulus + 1) / 2;

  ans = mod(ans*half, modulus);
    

  cout << ans << endl;
  
}
