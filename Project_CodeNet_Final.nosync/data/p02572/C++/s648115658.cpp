#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
signed main(){
  ll N,i,S=0,T=0,mod=1000000007,A,ans;cin>>N;
  REP(i,N){cin>>A;S+=A;S%=mod;T+=A*A%mod;T%=mod;}
  ans=S*S%mod-T;if(ans%2!=0)ans+=mod;ans/=2;ans%=mod;if(ans<0)ans+=mod;
  cout<<ans<<endl;
  return 0;
}