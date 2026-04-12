#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
signed main(){
  ll N,i,ans=0,m;cin>>N;ll A[N];REP(i,N)cin>>A[i];sort(A,A+N);
  if(N%2){
    REP(i,N){
      if(i<(N-1)/2)ans-=2*A[i];
      else if(i<(N+3)/2)ans+=A[i];
      else ans+=2*A[i];
    }
    m=ans;ans=0;reverse(A,A+N);
    REP(i,N){
      if(i<(N-1)/2)ans+=2*A[i];
      else if(i<(N+3)/2)ans-=A[i];
      else ans-=2*A[i];
    }
  }
  else{
    REP(i,N){
      if(i<N/2-1)ans-=2*A[i];
      else if(i<N/2)ans-=A[i];
      else if(i<N/2+1)ans+=A[i];
      else ans+=2*A[i];
    }
    m=ans;ans=0;reverse(A,A+N);
    REP(i,N){
      if(i<N/2-1)ans+=2*A[i];
      else if(i<N/2)ans+=A[i];
      else if(i<N/2+1)ans-=A[i];
      else ans-=2*A[i];
    }
  }
  cout<<max(ans,m)<<endl;
  return 0;
}