#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,ans = 1;cin>>n;
  vector<ll> cvec(n);
  for (ll i = 0; i < n; ++i) cin >> cvec[i];
  for (ll i = 1; i < n; ++i) {
    ll h = cvec[i];
    bool view = true;
    for (ll j = 0; j < i; ++ j) if (cvec[j] > h) view = false;
    if (view) ans += 1;
  }
  cout << ans << endl;
  return 0;
}