#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll mod=(1e9+7)*2;
  ll mod2=1e9+7;
  int n,q;
  cin>>n;
  q=1;
  ll vec[n];
  ll sum[n+1]={};
  ll sumb[n+1]={};
  for(int i=0;i<n;i++){
    cin>>vec[i];
    sum[i+1]=sum[i]+vec[i];
    sum[i+1]%=mod;
    sumb[i+1]=sumb[i]+vec[i]*vec[i];
    sumb[i+1]%=mod;
  }
  while(q--){
    int s,t;
    cin>>s>>t;
    s=1,t=n;
    ll ans=(sum[t]-sum[s-1])*(sum[t]-sum[s-1])-(sumb[t]-sumb[s-1]);
    ans%=mod;
    if(ans<0){
      ans+=mod*100;
    }
    ans%=mod;
    ans/=2;
    ans%=mod2;
    cout<<ans<<endl;
  }
}