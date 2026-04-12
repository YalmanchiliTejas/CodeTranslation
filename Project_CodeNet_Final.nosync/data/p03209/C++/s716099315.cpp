#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a(51);
vector<ll> p(51);

ll num(ll n, ll k) {
  ll res;
  if(k==a[n]) {
    res=p[n];
  }
  else if(k<2) {
    res=0;
  }
  else if(k>1&&k<=1+a[n-1]) {
    res=num(n-1,k-1);
  }
  else if(k==a[n-1]+2) {
    res = p[n-1]+1;
  }
  else if(k>a[n-1]+2&&k<a[n]) {
    res = p[n-1]+1+num(n-1,k-(a[n-1]+2));
  }
  return res;
}

int main() {
  ll n,k;
  cin >> n >> k;
  a[0]=1;
  p[0]=1;
  for(int i=0;i<n;i++) {
    a[i+1]=2*a[i]+3;
    p[i+1]=2*p[i]+1;
  }
  cout << num(n,k) << endl;
}