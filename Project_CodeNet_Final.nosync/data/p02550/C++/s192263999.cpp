#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <iostream>
#include <stdio.h>
#include <time.h>
 
using namespace std;

typedef long long ll;
 
#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define clr(a, b) memset((a), (b) ,sizeof(a))

ll d[100100];

int main(){
  clr(d,0);
  ll n,x,m;
  cin>>n>>x>>m;
  d[x] = 1;
  ll a = x;
  ll index = 2;
  ll s,e;
  while(1){
    a *= a;
    a %= m;
    if(d[a]!=0){
      s = d[a];
      e = index;
      break;
    }
    else{
      d[a] = index;
    }
    index++;
  }
  //cout << s << " " << e << endl;
  if(n<s){
    ll ans = 0;
    a = x;
    rep(i,0,n){
      ans += a;
      a *= a;
      a %= m;
    }
    cout << ans << endl;
    return 0;
  }
  ll l = e-s;
  a = x;
  ll ans = 0;
  rep(i,0,s){
    ans += a;
    a *= a;
    a %= m;
  }
  n -= s;
  if(l==0){
    cout << (ans+a*n)%m << endl;
    return 0;
  }
  ll b = a;
  ll ans2 = 0;
  rep(i,s,e){
    ans2 += b;
    b *= b;
    b %= m;
  }
  ll w = n/l;
  ans2 *= w;
  ll z = n%l;
  //cout << ans << endl;
  //cout << "a" <<  w << " " << z << endl;
  ll c = a;
  ll ans3 = 0;
  rep(i,0,z){
    //cout << c << endl;
    ans3 += c;
    c *= c;
    c %= m;
  }
  cout << ans+ans2+ans3 << endl;
  return 0;
}