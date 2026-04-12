#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e7 + 10;
const long long MOD = 998244353;

vector<long long> fact(MAXN);

long long gcde(long long a, long long b, long long *x, long long *y)
{
  if(a == 0)
  {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = gcde(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}

long long inv(long long a)
{
  long long x, y;
  long long g = gcde(a, MOD, &x, &y);
  assert(g == 1);
  long long res = (x % MOD + MOD) % MOD;
  return res;
}

void evalf()
{
  fact[0] = 1;
  for(int i = 1; i < MAXN; i++)
  {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
}

long long binary_expo(long long a, long long n)
{
  if(n == 0) return 1;
  if(n == 1) return a;
  long long p = binary_expo(a, n / 2);
  (p *= p) %= MOD;
  if(n & 1) (p *= a) %= MOD;
  return p;
}

long long ncr(long long n, long long r)
{
  long long ans = (fact[n] * inv(fact[n - r])) % MOD;
  (ans *= inv(fact[r])) %= MOD;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  evalf();
  long long n;
  cin >> n;
  long long ans = 1, nans = 0;
  for(int i = (n / 2) + 1; i <= n; i++)
  {
    long long ts = binary_expo(2, n - i);
    (ts *= ncr(n, i)) %= MOD;
    (nans += ts) %= MOD;
  }
  for(int i = 0; i < n; i++)
  {
    (ans *= 3) %= MOD;
  }
  (nans *= 2) %= MOD;
  ans = (((ans - nans) % MOD) + MOD) % MOD;
  cout << ans << endl;
  return 0;
}
