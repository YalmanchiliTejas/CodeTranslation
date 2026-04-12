#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int add(int a, int b) {
  return a + b - mod * (a + b >= mod);
}

int mul(int a, int b) {
  return int(1ll * a * b % mod);
}

int power(int a, int x) {
  if (x == 0) {
    return 1;
  }
  return mul(power(mul(a, a), x >> 1), (x & 1 ? a : 1));
}

int divide(int a, int b) {
  return mul(a, power(b, mod - 2));
}

int sub(int a, int b) {
  return a - b + mod * (a < b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  int ans = power(3, n), p = 2, c = 1;
  for (int i = n; i > n / 2; --i) {
    ans = sub(ans, mul(p, c));
    c = mul(c, i);
    c = divide(c, n - i + 1);
    p = add(p, p);
  }
  cout << ans;

  return 0;
}