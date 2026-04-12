#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll MOD = 1000000007;
  int n;
  cin >> n;
  vl a(n);
  rep(i,n) cin >> a[i];
  ll ans = 0;
  ll sum = 0;
  rep(i,n){
    sum += a[i];
    sum %= MOD;
  }
  rep(i,n){
    sum = (sum - a[i] + MOD)%MOD;
    ans += a[i]*sum;
    ans %= MOD;
  }
  ans += MOD;
  ans %= MOD;
  cout << ans << endl;
}