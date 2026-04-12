#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  ll n, k;
  cin >> n >> k;
  if(k == 0){
    cout << n*n << endl;
    return 0;
  }
  ll ans = 0;
  for(ll i = k+1; i < n+1; i++){
    ll add = n / i;
    add *= i - k;
    ll add2 = n % i;
    // cerr << i << " " << add << " " << add2 << endl;
    if(add2 >= k) add += add2 - k + 1;
    ans += add;
  }
  cout << ans << endl;
  return 0;
}