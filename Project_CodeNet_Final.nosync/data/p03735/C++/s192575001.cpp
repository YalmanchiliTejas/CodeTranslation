#include<bits/stdc++.h>
using namespace std;
using ll=long long;
static const ll INF=10000000000000;
ll N;
int main(){
  cin>>N;
  vector<pair<ll,ll>>A(N);
  for(int i=0;i<N;i++){
  ll x,y;cin>>x>>y;ll Y=max(x,y);ll X=min(x,y);
    pair<ll,ll>p(Y,X);
    A[i]=p;
  }sort(A.begin(),A.end());
  ll rm=INF;ll rM=0;ll bm=INF;ll bM=0;
  for(int i=0;i<N;i++){
  ll y=A[i].first;
    ll x=A[i].second;
    if(x<rm)rm=x;
    if(rM<x)rM=x;
    if(y<bm)bm=y;
    if(bM<y)bM=y;
   }ll ans1=(bM-bm)*(rM-rm);
       ll m=A[0].first;ll ans2=INF;ll M=0;
       for(int i=N-1;0<=i;i--){
       ll a=max(M,A[i].first)-m;if(a<ans2)ans2=a;
       if(A[i].second<m)m=A[i].second;if(M<A[i].second)M=A[i].second;
       }ans2*=(bM-rm);
       ll ans=min(ans1,ans2);
       cout<<ans<<endl;
  return 0;
}