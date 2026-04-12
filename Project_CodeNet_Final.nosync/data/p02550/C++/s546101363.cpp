#include<bits/stdc++.h>
using namespace std;
typedef int64_t ll;

ll n,x,m,again,idx=1,vis[100001],a[100001],ans=0;

int main(){
  cin>>n>>x>>m;
  if(n<=1e5){
    ll a2=x,idx2=1;
    ans+=a2;
    while(idx2<n){
      idx2++;
      a2=(a2*a2)%m;
      ans+=a2;
    }
    cout<<ans<<endl;
    return 0;
  }
  a[1]=x;
  vis[a[1]]=idx;
  ans+=x;
  n--;
  while(1){
    idx++;
    a[idx]=(a[idx-1]*a[idx-1])%m;
    if(vis[a[idx]]>0){again=idx;break;}
    n--;
    vis[a[idx]]=idx;
    ans+=a[idx];
  }
  ll period=again-vis[a[idx]];
  ll periodsum=0;
  for(int i=idx-period;i<idx;i++){
    periodsum+=a[i];
  }
  ans+=(n/period)*periodsum;
  n=n-(n/period)*period;
  for(int i=idx-period;i<idx-period+n;i++){
    ans+=a[i];
  }
  cout<<ans<<endl;
}
