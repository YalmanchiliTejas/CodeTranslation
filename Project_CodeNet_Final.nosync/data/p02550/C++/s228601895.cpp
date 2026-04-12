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
  ll N,X,M,i=1,ans;cin>>N>>X>>M;vector<ll>S(M,-1);
  S.at(X)=0;ll A[min(N,M+1)],B[min(N,M+1)];A[0]=X;B[0]=X;
  while(i<N){
    A[i]=A[i-1]*A[i-1]%M;B[i]=B[i-1]+A[i];
    if(S.at(A[i])!=-1)break;S.at(A[i])=i;i++;
  }
  if(i<N){
    ans=B[S.at(A[i])];N-=S.at(A[i])+1;ll T=i-S.at(A[i]),SUM=B[i]-B[S.at(A[i])];
    ans+=N/T*SUM+B[S.at(A[i])+N%T]-B[S.at(A[i])];
  }
  else ans=B[N-1];
  cout<<ans<<endl;
  return 0;
}