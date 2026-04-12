#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, k;
  cin >> n >>  k;
  ll ans = 0;
  for(ll i=k+1;i<=n;i++) {
    if(n%i == 0) {
      ans += (i-1-(k-1)) * (n/i);
    } else {
      ans += (i-1-(k-1)) * (n/i);
      if( k != 0)
        ans += max<ll>(0, n%i - k+1);
      else
        ans += max<ll>(0, n%i - k);
    }
  }
  cout << ans << endl;
}
