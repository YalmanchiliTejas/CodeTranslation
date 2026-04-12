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
  //Ai<10^5
  ll n, x, m;scanf("%lld %lld %lld", &n, &x, &m);
  vvl d = VV(m, 40, -1, ll);
  vvl s = VV(m, 40, -1, ll);

  for(ll i=0;i<40;i++){
    for(ll j=0;j<m;j++){
      if(i==0) {
        d[j][0] = (j*j)%m;
        s[j][0] = d[j][0];
      }else {
        d[j][i] = d[d[j][i-1]][i-1];
        s[j][i] = s[j][i-1] + s[d[j][i-1]][i-1];
      }
    }
  }

  auto f = [&](ll k){//k項目を求める
    int cnt = 0;
    ll ret = x;
    ll ans = x;
    while(k){
      if(k%2) {
        ans += s[ret][cnt];
        ret = d[ret][cnt];
      }
      k/=2;
      cnt++;
    }
    return ans;
  };
  std::cout << f(n-1) << '\n';
}
