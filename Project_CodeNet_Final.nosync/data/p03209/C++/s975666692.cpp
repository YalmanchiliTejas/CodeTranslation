#include <bits/stdc++.h>
using namespace std;
typedef long long int ll; typedef long double ld;
const int INF32 = 1e9+10;

ll pow2(int t, int n) {
  ll ans = 1;
  for (int i = 0; i < n; i++)
    ans *= t;
  return ans;
}

ll P(int n, ll x) {
  if (n == 0)
    return 1;
  else {
    if (x == 1)
      return 0;
    else if (x <= pow2(2, n+1)-2)
      return P(n-1, x-1);
    else if (x == pow2(2, n+1)-1)
      return pow2(2,n);
    else
      return pow2(2,n) + P(n-1, x+1-pow2(2,n+1));
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll N, X; cin >> N >> X;
  ll ans = P(N,X);
  cout << ans << endl;
}
