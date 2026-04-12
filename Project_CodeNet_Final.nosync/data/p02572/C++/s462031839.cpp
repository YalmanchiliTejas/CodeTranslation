#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll,ll>;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

const ull MOD = 1000000007;

int main(){
  ll n;cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  rep(i,n){
    cin >> a.at(i);
    sum += a.at(i);
    sum %= MOD;
  }

  ll ans = 0;

  for(ll i=0;i<n-1;++i){
    sum -= a.at(i);
    if( sum < 0 ) sum += MOD;
    ans += sum*a.at(i);
    ans %= MOD;
  }
  cout << ans%MOD << endl;
  return 0;

}