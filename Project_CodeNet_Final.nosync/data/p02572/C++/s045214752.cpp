#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF=1e9;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> b(n+1,0);
  rep(i,n) b[i+1] = b[i] + a[i];
  ll ans=0;
  int MOD=1000000007;
  rep(i,n) {
    ll sum=(b[n]-b[i+1])%MOD;
    ans += a[i]*sum;
    ans %= MOD;
  }
  cout << ans << endl;
}