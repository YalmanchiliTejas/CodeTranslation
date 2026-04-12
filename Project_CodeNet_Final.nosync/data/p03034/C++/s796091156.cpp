#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
 
const ll INF = 1ll<<60;
 
int main() {
  int n;
  cin >> n;
  vector<ll> s(n);
  rep(i,n) cin >> s[i];
  ll ans = 0;
  for (int c = 1; c < n; ++c) {
    ll score = 0;
    vector<bool> f(n);
    for (int x = 0; (x+1)*c < n-1 ; ++x) {
      int l = x*c, r = n-1-l; 
      if ( f[l] ) break;
      score += s[l], f[l] = true;
      if ( f[r] ) break;
      score += s[r], f[r] = true;
      ans = max(ans,score);
    }
  }
  cout << ans << endl;
  return 0;
}