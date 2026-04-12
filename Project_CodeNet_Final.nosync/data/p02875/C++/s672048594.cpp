#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

ll Power(ll x, int n) {
  ll result = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      n--;
      result *= x;
      result %= mod;
    } else {
      n /= 2;
      x *= x;
      x %= mod;
    }
  }
  return result;
}

ll Inverse(ll x) {
  ll result = Power(x, mod - 2);
  assert(result * x % mod == 1);
  return result;
}

ll GetC(int n, int k, const vector<ll>& fact) {
  ll result = fact[n];
  result *= Inverse(fact[k]);
  result %= mod;
  result *= Inverse(fact[n - k]);
  result %= mod;
  return result;
}

int main()
{
  int n;
  cin >> n;
  ll result = 1;
  for (int i = 0; i < n; ++i) {
    result *= 3;
    result %= mod;
  }
  vector<ll> pow2(n);
  pow2[0] = 1;
  for (int i = 1; i < n; ++i) {
    pow2[i] = pow2[i - 1] * 2 % mod;
  }

  vector<ll> fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = fact[i - 1] * i % mod;
  }

  for (int a = n / 2 + 1; a <= n; ++a) {
    ll cur = GetC(n, a, fact);
    cur *= pow2[n - a] * 2;
    cur %= mod;
    result -= cur;
    result %= mod;
    result += mod;
    result %= mod;
  }
  cout << result << endl;

  return 0;
}
