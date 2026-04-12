#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int MOD = 1000000007;
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n+1, 0);
  rep(i, n){
    cin >> a[i];
    b[i+1] = b[i] + a[i];
  }
  ll ans = 0;
  rep(i, n){
    ll sum = (b[n] - b[i+1]) % MOD;
    ans += a[i] * sum;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
