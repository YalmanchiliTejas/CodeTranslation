#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  ll n;
  cin >> n;
  
  ll a[n],b[n+1];
  b[0] = 0;
  ll mod = 1000000007;
  rep(i,n)
  {
    cin >> a[i];
    b[i+1] = a[i] + b[i];
  }
  
  ll ans = 0;
  rep(i,n)
  {
    ll sum = (b[n] - b[i+1]) % mod;
    ans += a[i] * sum;
    ans %= mod;
  }
  
  cout << ans << endl;
}