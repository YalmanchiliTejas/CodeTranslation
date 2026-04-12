#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  long long a, b, x;
  cin >> a >> b >> x;
  long long k = max(0LL, (x - b) / (a - b));
  x %= mod;
  k %= mod;
  b %= mod;
  cout << (x + k * b % mod) % mod << endl;
  return 0;	
}
