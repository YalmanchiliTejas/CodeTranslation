#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  if(k == 0){
    cout << (ll)n*n << endl;
    return 0;
  }
  ll ans = 0;
  rep2(b, k+1, n+1){
    ans += (ll)(n+1)/b*(b-k);
    int m = (n+1)%b;
    if(m-k > 0) ans += m-k;
  }
  cout << ans << endl;
  return 0;
}