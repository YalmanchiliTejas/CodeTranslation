#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x;
ll kai(ll n,ll k){
  ll ret=1;
  for(ll i=0;i<k;i++)ret*=n;
  return ret;
}
ll dfs(ll u,ll d,ll k){
  if(k==0)return 1;
  ll mid=(u+d)/2;
  //cout<<mid<<endl;
  ll ret=0;
  if(x<mid){
    if(x==d)ret=0;
    else if(x==mid-1)ret+=kai(2,k)-1;
    else ret+=dfs(mid-1,d+1,k-1);
  }
  if(x==mid)ret+=pow(2,k);
  if(x>mid){
    if(x==u)ret+=kai(2,k+1)-1;
    else ret+=kai(2,k)+dfs(u-1,mid+1,k-1);
  }
  return ret;
}
int main(){
  //for(ll i=0;i<52;i++)t*=2;
  //cout<<t;return 0;
  cin>>n>>x;
  ll ans=dfs(kai(2,n+2)-3,1,n);
  cout<<ans<<endl;
}