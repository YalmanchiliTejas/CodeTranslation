#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;

#define ll long long int
#define pb push_back
#define RONALDO            \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define endl "\n"
#define pii pair<ll, ll>
#define ff first
#define ss second
#define mod 1000000007
#define vi vector<ll>
#define mi map<char, ll>
#define Max(x, y, z) max(x, max(y, z))
#define Min(x, y, z) min(x, min(y, z))
//LOVE U MESSI && CRistiano !!

//INSPIRATIONAL MICHAEL PHELPS && USAIN BOLT !!

int main()
{
  RONALDO;
  ll n;
  cin >> n;
  ll a[n], b[n], ans = 0;
  vi v;
  for (ll i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  b[0] = a[0];
  for (ll i = 1; i < n; i++)
  {
    b[i] =b[i - 1] + a[i];
  }
  for (ll i = 0; i < n - 1; i++)
  {
    ans += ((b[i]%mod) * (a[i + 1]%mod)) % mod;
  }
  cout << ans%mod;
}