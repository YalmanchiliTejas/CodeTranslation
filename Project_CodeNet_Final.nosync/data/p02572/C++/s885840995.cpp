#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n; cin >> n;
  ll m = 1000000007;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll c = 0, ans = 0;
  rep(i,n-1) {
    c = (c + a[i]) % m;
    ans = (ans + (c * a[i+1] % m)) % m;
  }
  cout << ans << endl;
  return 0;
}