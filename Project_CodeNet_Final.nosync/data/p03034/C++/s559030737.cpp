#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll val[100005]={0};
bool used[100005];
int main(){
  ll n,ans=0;
  cin>>n;
  for(int i=0;i<n;i++) used[i]=false;
  for(int i=0;i<n;i++) cin>>val[i];
  for(ll d=1;d<n;d++){
    ll l=0,r=0;
    for(int i=0;i<n;i+=d){
      if(used[i]) break;
      used[i]=true;
      if(used[n-i-1]) break;
      used[n-i-1]=true;
      if(n-i-1<=d) break;
      l+=val[i];
      r+=val[n-i-1];
      ans=max(ans,l+r);
    }
    for(int i=0;i<n;i+=d) used[i]=false;
    for(int i=n-1;i>=0;i-=d) used[i]=false;
  }
  cout<<ans<<endl;
}
