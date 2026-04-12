#include <iostream>

long long ext_gcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = ext_gcd(b, a%b, x, y);
  long long old_x = x;
  long long old_y = y;
  x = old_y;
  y = old_x - a/b * old_y;
  return d;
}

int main() {
  int n; std::cin >> n;
  long long mod = 1e9+7;
  // std::cout << mod << std::endl;
  long long x, y;
  long long gcd = ext_gcd(2, mod, x, y);
  int inv2 = x;
  // std::cout << "inv2: " << inv2 << std::endl;

  long long sum = 0;
  long long squ_sum = 0;

  while (n--) {
    long long a; std::cin >> a; 
    sum += a;
    sum %= mod;

    squ_sum += a*a; 
    squ_sum %= mod;
  }

  long long ans = (sum*sum - squ_sum) % mod;
  ans *= inv2;
  ans %= mod;
  if (ans < 0) ans += mod;
  std::cout << ans << std::endl;

  return 0;

}
