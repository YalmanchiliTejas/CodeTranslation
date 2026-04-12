#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const ll INF = 1e18;

int main(){
  ll n;
  cin >> n;
  ll a[n];
  rep(i,n) cin >> a[i];
  ll ans = 0;
  while(true) {
    bool can = true;
    rep(i,n) {
      if(a[i] >= n) can = false;
    }
    if(can) break;
    ll sum = 0;
    rep(i,n) {
      ans += a[i]/n;
      sum += a[i]/n;
    }
    rep(i,n) a[i] = (a[i] % n) + sum - a[i]/n;
  }
  cout << ans << endl;
  return 0;
}