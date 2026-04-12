#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
const ll MOD = 1e9+7;

int main(){
  ll n,x;
  cin>>n>>x;
  ll p[55],b[55];
  p[0]=b[0]=1;
  for(int i=1;i<55;i++){
    p[i]=p[i-1]*2+1;
    b[i]=b[i-1]*2+3;
  }
  ll ans=0;
  while(1){
    ll f=1;
    for(ll i=0;i<n;i++){
	 ll k=b[n-i]/2+1+i;
	 if(b[n-i]+i==x){
	   x=0;
	   ans+=p[n-i];
	   break;
	 }
	 if(k<=x){
	   ans+=p[n-i-1]+1;
	   x-=k;
	   n-=i+1;
	   f=0;
	   break;
	 }
    }
    if(f){
	 if(n<x)ans++;
	 break;
    }
  }
  cout<<ans<<endl;
  return 0;
}
