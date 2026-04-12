#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "math.h"
#include "cstring"
#include "stack"
#include "queue"

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int> > mat;

const ll mod = 1e9 + 7;

ll power_ll_p(ll a, ll b, ll p)	//F_pでのべき
{
  if (b > p)
  {
    b %= (p - 1);//位数p-1
  }
  if (b == 0)
  {
    return 1;
  }
  if (b % 2 == 0)
  {
    ll t = power_ll_p(a, b / 2, p);
    return t * t % p;
  }
  else
  {
    return a * power_ll_p(a, b - 1, p) % p;
  }
}


ll combination_p(ll n, ll r, ll p)	//コンビネーション
{
  if (r > n - r)
  {
    r = n - r;
  }
  ll ans = 1;
  for (ll i = 0; i < r; i++)
  {
    ans *= n - i;
    ans %= p;
  }
  ll subans = 1;
  for (ll i = 0; i < r; i++)
  {
    subans *= i + 1;
    subans %= p;
  }
  ans *= power_ll_p(subans, p - 2, p);		//逆元は^(p-2)
  ans %= p;
  return ans;
}

ll extgcd(ll a, ll b, ll&x, ll&y)
{
  if (b == 0)
  {
    x = 1;
    y = 0;
    return a;
  }
  else
  {
    ll q = a / b;
    ll g = extgcd(b, a - q * b, x, y);
    ll z = x - q * y;
    x = y;
    y = z;
    return g;
  }
}

//modp逆元
ll inversemod(ll a, ll p)
{
  ll x, y;
  extgcd(a, p, x, y);
  x %= p;
  if (x < 0)
  {
    x += p;
  }
  return x;
}

int main()
{
  ll n, m, k;
  cin >> n >> m >> k;
  ll x = m * (n * n - 1) + n * (m * m - 1);
  x %= mod;
  x *= m * n;
  x %= mod;
  x *= inversemod(6, mod);
  x %= mod;
  x *= combination_p(n * m - 2, k - 2, mod);
  cout << ((x % mod) + mod) % mod << "\n";
}