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


int main(){
  ll n, x, P;
  ll Q = 1, T = 1;
  vector<ll> tbl(200000, -1);//x^2^i mod P
  std::cin >> n >> x >> P;
  if(x==0){
    std::cout << 0 << '\n';
    return 0;
  }

  T = x;
  ll st = -1;
  ll O = -1;
  for(;;Q++){
    if(tbl[T]!=-1){
      Q -= tbl[T];
      st = tbl[T];
      O = T;
      break;
    }
    tbl[T] = Q;
    T *= T;
    T %= P;
  }
  if(tbl[0]!=-1){
    ll lim = tbl[0];
    ll ans = 0;
    ll t = x;
    for(int i=0;i<min(lim, n);i++){
      ans += t;
      t = (t * t)%P;
    }
    std::cout << ans << '\n';
    return 0;
  }


  ll num = (n - st + 1) / Q;
  ll amari = (n - st + 1) % Q;
  ll cnt = 0;
  ll ans = 0;
  T = O;
  for(int i=0;i<Q;i++){
    cnt += T;
    T *= T;
    T %= P;
  }
  T = O;
  for(int i=0;i<amari;i++){
    ans += T;
    T *= T;
    T %= P;
  }
  T = x;
  for(int i=0;i<st-1;i++){
    ans += T;
    T *= T;
    T %=P;
  }
  std::cout << ans + num * cnt << '\n';
}
