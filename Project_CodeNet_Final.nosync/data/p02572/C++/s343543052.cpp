#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
const ll mod = 1e9+7;

int main() {
  ll n;
  cin >> n;
  vl a(n);
  rep(i,n) cin >> a[i];
  
  ll sum = 0;
  rep(i,n) sum += a[i];
  vl b(n);
  b[0] = sum - a[0];
  rep(i,n-1) b[i+1] = b[i] - a[i+1];
  
  ll ans = 0;
  rep(i,n-1) ans += (a[i] % mod) * (b[i] % mod) % mod;
  ans %= mod;
  cout << ans << endl;
}