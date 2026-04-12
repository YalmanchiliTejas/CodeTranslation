#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define For(i,a,b) for(i=a;i<b;i++)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define vsort(v) sort(v.begin(),v.end())
ll labs(ll a){return (a>0)?a:(0-a);}

int main(){
  ll i,j,X,N,mid,ans=0;
  cin>>N>>X;
  vector<ll> paty(N+1,1),level(N+1,1);
  rep1(i,N+1){
    paty[i]=paty[i-1]*2+1;
    level[i]=level[i-1]*2+3;
  }
  while(1){
    mid=(1+level[N])/2;
    if(X==mid){
      if(N==0){ans+=1;}
      else{ans+=paty[N-1]+1;}
      break;
    }
    if(X==1)break;
    if(X==level[N]){
      ans+=paty[N];
      break;
    }
    N--;
    if(level[N]+2<X){
      ans+=paty[N]+1;
      X-=(level[N]+2);
    }else{X--;}
  }
  cout<<ans<<endl;
  return 0;
}