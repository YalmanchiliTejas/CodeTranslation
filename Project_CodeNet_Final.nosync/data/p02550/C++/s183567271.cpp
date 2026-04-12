#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll N,X,M;
int main(){
  cin>>N>>X>>M;
  if(N<=M){
  ll ans=0;ll a=X;
    for(ll i=0;i<N;i++){
    ans+=a;
      a=(a*a)%M;
    }cout<<ans<<endl;
      
  }else{
  set<ll>S;ll a=X;ll I,r;
    for(ll i=0;i<N;i++){
    if(S.count(a)){I=i-1;r=a;break;}
      S.insert(a);
      a=(a*a)%M;
    }a=X;
    ll ans=0;ll J;
    for(ll i=0;i<N;i++){
    if(a!=r){ans+=a;a=(a*a)%M;}else{J=i;break;}
     }
  ll A=(I-J+1);ll B=(N-J)%A;ll C=(N-J)/A;
    ll sum=0;ll R=r;
    for(ll i=J;i<=I;i++){
    sum+=R;R=(R*R)%M;
    }ll y=0;ll R1=r;
    for(ll i=J;i<J+B;i++){
    y+=R1;R1=(R1*R1)%M;
    }ans+=(sum*C+y);
      
      cout<<ans<<endl;
   }
  return 0;
}
  