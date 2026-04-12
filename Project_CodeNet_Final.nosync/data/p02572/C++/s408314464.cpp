#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

long long modpow(long long x, long long y){
    if (y == 0) return 1;
    if (y % 2) return x * modpow(x, y - 1) % mod;
    long long res = modpow(x, y / 2);
    return res * res % mod;
}

int main(void)
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> acc(n + 1, 0);
  for (int i = 0; i < n; i++) acc[i + 1] = (acc[i] + a[i]) % mod;
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += (long long)((mod + acc[n] - a[i]) % mod) * a[i] % mod;
    ans %= mod;
  }
  ans *= modpow(2, mod - 2);
  ans %= mod;
  cout << ans << endl;
}