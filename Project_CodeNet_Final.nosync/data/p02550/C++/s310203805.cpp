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
  ll n, x, m;
  cin >> n >> x >> m;
  vector<bool> mgp(m, false);
  mgp.at(x) = true;
  int loop_find = -1;
  ll ans = x;
  for(ll i = 1; i < n; i++){
    x = (x*x) % m;
    if(mgp.at(x) == true){
      loop_find = x;
      n -= i;
      break;
    }else{
      mgp.at(x) = true;
      ans += x;
    }
  }
  if(loop_find == -1){
    cout << ans << endl;
    return 0;
  }

  ll looptot = -1;
  int sz = 0;
  x = loop_find;
  while(!(looptot != -1 && x == loop_find)){
    if(looptot == -1) looptot = 0;
    looptot += x;
    x = (x*x) % m;
    sz++;
  }
  ans += n/sz*looptot;
  n %= sz;
  rep(i, n){
    ans += x;
    x = (x*x) % m;
  }
  cout << ans << endl;

  return 0;
}