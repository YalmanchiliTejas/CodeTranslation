#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll a,b,c,x,y;cin>>a>>b>>c>>x>>y;
  ll m=min(2*c,a+b);
  ll ans=0;
  ans+=m*min(x,y);
  ll ama=abs(x-y);
  if(x>=y){
    ll n=min(a,2*c);
    ans+=ama*n;
  }
  else{
    ll n=min(b,2*c);
    ans+=ama*n;
  }
  cout<<ans<<endl;
}