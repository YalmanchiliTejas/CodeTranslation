// -----------------------------------
// Author     : MatsuTaku
// Affiliation: Tokushima University
// Country    : Japan
// Date       : 04/08/2020
// -----------------------------------

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int n,k; cin>>n>>k;
  ll ans=0;
  if (k == 0)
    ans = (ll)n*n;
  else {
    for (ll b = k+1; b <= n; b++) {
      ans += (b-k)*(n/b);
      if (n%b>=k)
        ans += n%b-k+1;
    }
  }
  cout << ans << endl;

  return 0;
}
