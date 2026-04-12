#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug "<< i << std::endl

// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n,ans=0;
  std::cin>>n;

  bool flag=false;

  std::vector<ll> a(n);
  rep(i,0,n){
    std::cin>>a[i];
    if(a[i]>=n)flag=true;
  }

  while(flag){
    ll temp=0;
    rep(i,0,n)temp+=a[i]/n;
    rep(i,0,n){
      ll now=a[i];
      a[i]-=(now/n)*n;
      a[i]+=(temp-(now/n));
    }

    ans+=temp;

    flag=false;
    rep(i,0,n)if(a[i]>=n)flag=true;
  }

  std::cout<<ans;

  return 0;
}
