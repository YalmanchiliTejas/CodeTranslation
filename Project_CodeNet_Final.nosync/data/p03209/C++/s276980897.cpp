#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

vector<P> v;
ll f(int n, ll x){
  if(x<=0) return 0;
  ll p = v[n].first, b = v[n].second;
  if(x==p+b) return p;

  p = v[n-1].first, b = v[n-1].second;
  ll res;
  if(x>=p+b+2){
    res = f(n-1,x-p-b-2) + 1 + p;
  }else{
    res = f(n-1,x-1);
  }
  return res;
}
int main() {
  int n; ll x;
  cin >> n >> x;
  v = vector<P>(n+1);
  v[0] = P(1,0);
  rep(i,n) v[i+1] = P(v[i].first*2+1,v[i].second*2+2);
  cout << f(n,x) << endl;
}