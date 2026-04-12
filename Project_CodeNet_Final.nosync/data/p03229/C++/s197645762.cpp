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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(snip_i, n) cin >> a.at(snip_i);
  sort(a.begin(), a.end());

  // rep(i, n){
  //   if(i != 0) cerr << " ";
  //   cerr << a.at(i);
  // }
  // cerr << endl;

  ll ans = 0, add = 0;
  if(n % 2 == 1){
    rep(i, n){
      if(i < n/2) ans -= a.at(i)*2;
      else if(i < n/2+2) ans += a.at(i);
      else ans += a.at(i) * 2;
    }
    rep(i, n){
      if(i < (n+1)/2){
        if((n+1)/2-3 < i){
          add -= a.at(i);
        }else add -= a.at(i)*2;
      }else add += a.at(i) * 2;
    }
  }else{
    rep(i, n){
      if(i < n/2){
        if(i != n/2-1) ans -= a.at(i)*2;
        else ans -= a.at(i);
      }else{
        if(i != n/2) ans += a.at(i)*2;
        else ans += a.at(i);
      }
    }
  }
  // cerr << ans << " " << add << endl;
  ans = max(ans, add);
  cout << ans << endl;
  // int bg, sm;
  // rep(i, n){
  //   if(i % 2 == 0){
  //     bg = a.at(n-i/2-1);
  //     if(i == 0) continue;
  //   }else{
  //     sm = a.at(i/2);
  //   }
  //   ans += bg - sm;
  // }
  // ll add = 0;
  // rep(i, n){
  //   if(i % 2 == 0){
  //     sm = a.at(i/2);
  //     if(i == 0) continue;
  //   }else{
  //     bg = a.at(n-i/2-1);
  //   }
  //   add += bg - sm;
  // }
  // cerr << ans << " " << add << endl;
  // ans = max(ans, add);
  // cout << ans << endl;
  return 0;
}