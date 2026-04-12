#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  ll n,mod = 1e9+7;
  cin >> n;
  vector<ll>a(n);
  vector<ll>sum(n+1);
  rep(i,0,n){
    cin >> a[i];
    sum[i+1] = a[i]+sum[i];
  }
  ll ans = 0;
  rep(i,0,n){
    ll tmp = ((a[i]%mod)*((sum[n]-sum[i+1])%mod))%mod;
    ans = (ans+tmp)%mod;
  }
  cout << ans << endl;
}