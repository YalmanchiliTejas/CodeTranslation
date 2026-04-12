#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n;cin>>n;
  vector<ll> a(n);
  rep(i, n)cin>>a[i];
  sort(a.begin(), a.end());

  vector<ll> c(n);
  rep(i,n) c[i]=2*(i%2 ? -1 : 1);
  c[0]/=2;
  c[n-1]/=2;

  sort(c.begin(), c.end());
  ll r1=0;
  rep(i,n) r1 += a[i]*c[i];

  rep(i,n)c[i]*=-1;
  sort(c.begin(), c.end());

  ll r2=0;
  rep(i,n)r2 += a[i]*c[i];

  cout<<max(r1, r2);

  return 0;
}