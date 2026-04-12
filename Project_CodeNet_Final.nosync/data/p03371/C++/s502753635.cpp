#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  ll ans=ll(1e18);
  for(ll i=0;i<=2*max(x,y);i+=2){
    ll tmp=i*c;
    tmp+=max(0LL,x-i/2)*a+max(0LL,y-i/2)*b;
    ans=min(ans,tmp);
  }
  cout<<ans<<endl;
}