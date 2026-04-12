#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
const int M = 1e9+7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> c(n+1);
  for (int i = n-1; i >= 0; --i) {
    c[i] = c[i+1] + a[i];
    c[i] %= M;
  }
  ll ans = 0;
  for (int i = 0; i < n-1; ++i) {
    ll tmp = a[i] * c[i+1] % M;
    ans = (ans + tmp) % M;
  }
  cout << ans << endl;
}