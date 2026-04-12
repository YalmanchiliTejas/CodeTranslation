#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  sort(rng(a));
  ll ans = 0;
  ll s = 0, t = 0;
  if(n%2==1) {
    rep(i,n/2) {
      s += 2*a[n-i-1];
      t -= 2*a[i];
    }
    s -= a[n/2]+a[n/2-1];
    t += a[n/2]+a[n/2+1];
    for(int i = n/2+2; i < n; i++) {
      s -= 2*a[n-i-1];
      t += 2*a[i];
    }
    ans = max(s,t);
  }
  else {
    // rep(i,n/2-1) ans += 2*a[i+n/2+1]-2*a[i];
    rep(i,n/2-1) ans -= 2*a[i];
    ans += a[n/2]-a[n/2-1];
    for(int i = n/2+1; i < n; i++) ans += 2*a[i];
  }
  cout << ans << endl;
  return 0;
}