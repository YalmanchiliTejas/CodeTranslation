#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
 
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
 
  ll ans = 0;
  for (int c = 1; c <= n-1; c++) {
    ll score = 0;
    vector<char> v(n,'0');
    for (int x = 0;(x+1)*c < n-1;x++) {
      if(v[x*c] == '1') break;
      score += a[x*c];
      v[x*c] = '1';
      if(v[n-1-x*c] == '1') break;
      score += a[n-1-x*c];
      v[n-1-x*c] = '1';
      ans = max(ans,score);
    }
  }
  cout << ans << endl;
}