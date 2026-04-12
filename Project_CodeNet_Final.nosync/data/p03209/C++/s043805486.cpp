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

ll tot(int lv){
  if(lv == 0) return 1;
  else return tot(lv-1)*2+3;
}

ll in(map<int, ll> &mp, int lv){
  if(lv == 0) return mp[lv] = 1;
  if(mp[lv] != 0) return mp[lv];
  mp[lv] = 1 + 2*in(mp, lv-1);
  return mp[lv];
}

ll fc(int lv, ll x, ll l, ll r){
  static map<int, ll> mp;
  if(mp[0] == 0) in(mp, lv);
  ll mid = (l+r)/2;
  if(r <= x) return mp[lv];
  if(mid < x && x < r){
    return mp[lv-1] + 1 + fc(lv-1, x, mid+1, r-1);
  }
  if(mid == x) return mp[lv-1] + 1;
  if(x == l) return 0;
  return fc(lv-1, x, l+1, mid-1);
}

int main(){
  int n;
  cin >> n;
  ll x;
  cin >> x;
  ll mx = tot(n);
  cout << fc(n, x, 1, mx) << endl;
  return 0;
}