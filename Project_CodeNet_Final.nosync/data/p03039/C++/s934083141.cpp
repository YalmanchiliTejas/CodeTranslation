#include "bits/stdc++.h"
using namespace std;
 
#define REP(i, n) for(ll i = 0;i < n;i++)
#define REP1(i, n) for(ll i = 1;i < n;i++)
#define REPR(i, n) for(ll i = n-1;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
 
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
 
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
 
#define pb(a) push_back(a)
 
ll n,m,k;
ll cnst=1000000007LL;

ll moddiv(ll a,ll b,ll c){
	ll x0=c;
	ll x1=b;
  ll x2;
	ll n0=0LL;
	ll n1=1LL;
  ll n2;
	ll t=a%b;
  ll m;
  ll ans;
	if (t==0) return a/b;
		for(int i=0;i<900;i++){
      m=x0/x1;
      x2=x0-x1*m;
      n2=n0-m*n1;
      n2%=c;
      if (x2==1){
        ans=(n2+c)%c;
        break;
      }
      x0=x1;
      x1=x2;
      n0=n1;
      n1=n2;
    }
	ans=a+((t*ans)%c)*b-t;
	return ans/b;
}





 
int main(){
  ll ans=0LL;
  cin >> n >> m >> k;
  ll k2ans=0LL;
  REP(x,m){
    REP(y,n){
      ll x1=m-x-1;
      ll xline=x*(x+1)/2+x1*(x1+1)/2;
      ll y1=n-y-1;
      ll yline=y*(y+1)/2+y1*(y1+1)/2;
      k2ans+=xline*n+yline*m;
      k2ans%=cnst;
    }
  }
  
  k2ans=moddiv(k2ans,2LL,cnst);
  ll nmt=k2ans;
  k-=2;
  ll nm=n*m;

  REP(i,k){
    nmt=nmt*(nm-2-i);
    nmt%=cnst;
    nmt=moddiv(nmt,i+1,cnst);
  }
  
  ans=nmt;
  cout<<ans<<endl;
 
  return 0;
}