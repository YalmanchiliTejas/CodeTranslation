#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


ll a[55], p[55]; // a: 層数,p: パティ数

ll f(ll s, ll t) {
  if(t<=1) {
    if(s==0) return 1;
    return 0;
  }
  if(t<=1+a[s-1]) return f(s-1,t-1);
  if(t==1+a[s-1]+1) return p[s-1]+1;
  if(t==2*a[s-1]+3) return p[s];
  return p[s-1] + 1 + f(s-1,t-2-a[s-1]);
}
int main() {
  ll n, x;
  cin >> n >> x;
  a[0] = p[0] = 1;
  rep(i,n) {
    a[i+1] = 2*a[i]+3;
    p[i+1] = 2*p[i]+1;
  }
  cout << f(n,x) << endl;
  return 0;
}