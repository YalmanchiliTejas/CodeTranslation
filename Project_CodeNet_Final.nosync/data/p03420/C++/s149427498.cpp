#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ll n,k;

  cin >> n >> k;

  ll ans = 0;

  if(k == 0) {
    cout << n * n << endl;
    return 0;
  }

  for(ll b = k + 1; b <= n; b++) {
    ll p = n / b;
    ll q = n % b;
    ll y = max((ll)0,q - k + 1);
    ll x = b - k - y;
    ans += (p + 1) * y + p * x;

  }

  cout << ans << endl;
}
  
