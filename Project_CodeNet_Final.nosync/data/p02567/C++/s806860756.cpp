#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <cassert>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d>>(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

struct segtree{
  ll M=1, INIT;
  vector<ll> dat;
  segtree(ll N, ll num):INIT(num){
    while(M<N) M*=2;
    dat.resize(M*2-1, num);
  }
  void update(ll x, ll k){
    k+=M-1;
    dat[k] = x;
    while(k>0) k = (k-1)/2, dat[k] = max(dat[k*2+1],dat[k*2+2]);
  }
  ll query(ll a, ll b=-1, ll k=0, ll l=0, ll r=-1){
    if(r==-1) r = M;
    if(b==-1) b = M;
    if(r<=a || b<=l) return INIT;
    if(a<=l && r<=b) return dat[k];
    ll A = query(a, b, k*2+1, l, (l+r)/2);
    ll B = query(a, b, k*2+2, (l+r)/2, r);
    return max(A, B);
  }
};


int main(){
  ll INF = 10000000000;
  ll n, q;scanf("%lld %lld", &n, &q);
  segtree seg(n, -INF);
  for(int i=0;i<n;i++){
    ll a;scanf("%lld", &a);
    seg.update(a, i);
  }
  for(int i=0;i<q;i++){
    ll t, a, b;scanf("%lld %lld %lld", &t, &a, &b);
    a--;

    if(t==1) seg.update(b, a);
    else if(t==2) printf("%lld\n", seg.query(a, b));
    else{
      if(seg.query(a, n)<b){
        printf("%lld\n", n+1);
        continue;
      }
      ll l = a-1, r = n-1;//l:ない　
      while(r-l>1){
        ll mid = (l + r)/2;
        if(seg.query(a, mid+1)<b) l = mid;
        else r = mid;
      }
      printf("%lld\n", r+1);
    }
  }
}
