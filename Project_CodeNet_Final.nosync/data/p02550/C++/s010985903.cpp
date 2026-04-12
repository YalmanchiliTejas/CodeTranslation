#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n,x,m;
  cin >> n >> x >> m;
  vector<ll> v(m,-1);
  ll j=0;
  ll f=0;
  ll i=x;
  ll a=0;
  ll b=0;
  while(f==0){
    if (v[i]==-1){
      v[i]=j;
    }else{
      a=v[i];
      b=j;
      f=1;
    }
    i=(i*i)%m;
    j++;
  }
  ll s=0;
  ll p=0;
  ll q=0;
  rep(i,m){
    if (v[i]<a && v[i]!=-1) p+=i;
    if (a<=v[i] && v[i]<b) s+=i;
    if (a<=v[i] && v[i]<(n-a)%(b-a)+a) q+=i;
  }
  ll res=s*((n-a)/(b-a))+p+q;
  cout << res << endl;
  return 0;
}
