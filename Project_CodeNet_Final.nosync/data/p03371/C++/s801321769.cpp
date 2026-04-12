#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(void)
{
  ll a, b, c;
  ll x, y;
  cin >> a >> b >> c >> x >> y;
  ll p, pmin = -1;
  ll imax = max(x, y) * 2;
  for(ll i = 0; i <= imax; i += 2) {
    p = max(0ll,(x - i / 2)) * a + max(0ll,(y - i / 2)) * b + c * i;
    if(pmin > 0) {
      pmin = min(pmin, p);
    } else {
      pmin = p;
    }
  }
  cout << pmin << endl;
}
