#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define F .first
#define S .second 
using ll=long long;
using ld=long double;
using namespace std;
const ll mod=1e9+7;
ll funca(ll n){
  if(n==0)return 1;
  else return funca(n-1)*2+3;
}
ll funcp(ll n){
  if(n==0)return 1;
  else return funcp(n-1)*2+1;
}
ll funcans(ll n,ll x){
  if(x==1){
   if(n!=0) return 0;
   else return 1;
  }
  else if(x>1&&x<funca(n-1)+2)return funcans(n-1,x-1);
  else if(x==funca(n-1)+2)return funcp(n-1)+1;
  else if(x>funca(n-1)+2&&x<funca(n))return funcp(n-1)+1+funcans(n-1,x-2-funca(n-1));
  else return funcp(n);
}
main(){
  ll n,x;
  cin>>n>>x;
  cout<<funcans(n,x)<<endl;
}
