#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0;i < n;i++)
#define FOR(i, m, n) for(ll i = m;i < n;i++)

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  ll ans = 0;
  FOR(i, 1, n+1) {
    ans += (n+1)/i * max((ll)0, i-k) + max((ll)0, (n+1)%i-k);
  }
  if (k == 0) ans -= n;
  cout << ans << endl;
}