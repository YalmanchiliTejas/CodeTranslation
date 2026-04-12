#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define pi pair<int, int>
#define fir first
#define sec second
#define MAXN 19
#define mod 1000000007

int modpow(int x, int y)
{
  int z = 1;
  while (y)
  {
    if (y & 1)
      z = (z * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return z;
}
int inverse(int x)
{
  return modpow(x, mod - 2);
}
int divide(int x, int y)
{
  return (x * inverse(y)) % mod;
}
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n);
  int acc = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    acc = (acc + v[i]) % mod;
  }
  acc = (acc * acc) % mod;
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = (ans + (v[i] * v[i])) % mod;
  cout << divide((acc - ans + mod) % mod, 2) << endl;
  return 0;
}
