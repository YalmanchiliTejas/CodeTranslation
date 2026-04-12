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
  vector<int> chk(m, -1);
  vector<ll> loop;
  while(chk.at(x) == -1){
    chk.at(x) = loop.size();
    loop.push_back(x);
    x = (x*x) % m;
  }
  ll ans = 0;
  // for(auto i : chk) cerr << i << " ";
  // cerr << endl;
  // for(auto p : loop) cerr << p << " ";
  // cerr << endl;
  if(n < loop.size()){
    rep(i, n){
      ans += loop.at(i);
    }
  }else{
    int pos = chk.at(x);
    ll lsum = 0;
    rep(i, loop.size()){
      if(pos <= i) lsum += loop.at(i);
      ans += loop.at(i);
    }
    ll sz = loop.size() - pos;
    n -= loop.size();
    ans += lsum*(n/sz);
    n %= sz;
    rep(i, n){
      ans += loop.at(i+pos);
    }
  }
  cout << ans << endl;
  return 0;
}