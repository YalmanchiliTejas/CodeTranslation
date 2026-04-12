#include <bits/stdc++.h>

using namespace std;


#define MAXN 1000000
typedef long long ll;
int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  for (ll b = k+1; b <= n; ++b) {
    ans += (n-k)/b*(b-k) + min(b-k, n-k-(n-k)/b*b+1) - (k==0);
  }
  cout << ans << endl;
  return 0;
}
