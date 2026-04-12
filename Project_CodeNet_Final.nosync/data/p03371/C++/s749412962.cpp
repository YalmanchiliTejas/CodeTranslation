#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)

const ll MOD = 1000000007;
const ll INF = 1e18; //1*10^18

ll powll(ll a, ll n)
{ //O(log n)
  ll res = 1;
  while (n > 0)
  {
    if (n & 1) //(n & 1)=(n % 2 !=0)
    {
      res = res * a;
    }
    a = a * a;
    n >>= 1; //(n & 1)=(n % 2 !=0)
  }
  return res;
}

ll modpow(ll a, ll n, ll mod) //O(log n)
{
  ll res = 1;
  while (n > 0)
  {
    if (n & 1) //(n & 1)=(n % 2 !=0)
    {
      res = res * a % mod;
    }
    a = a * a % mod;
    n >>= 1; //(n>>=1)=(n/2)
  }
  return res;
}

int ReturnDigit(ll num)
{
  string number = to_string(num);
  return number.length();
}

const ll MAX = 1e4;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit()
{
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main()
{
  // srand((unsigned int)time(NULL));//--> rand()
  ll i, j, k, l, ans = 0;
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  if (c * 2 <= a && c * 2 <= b)
  {
    ans = max(x, y) * c * 2;
  }
  else if (c * 2 <= a)
  {
    ans += x * c * 2;
    y = max(0ll, y - x);
    ans += y * b;
  }
  else if (c * 2 <= b)
  {
    ans += y * c * 2;
    x = max(0ll, x - y);
    ans += x * a;
  }
  else if (c * 2 <= a + b)
  {
    ans += min(x, y) * c * 2;
    if (x < y)
    {
      ans += (y - x) * b;
    }
    else
    {
      ans += (x - y) * a;
    }
  }
  else
  {
    ans += x * a + y * b;
  }

  cout << ans << endl;
}
