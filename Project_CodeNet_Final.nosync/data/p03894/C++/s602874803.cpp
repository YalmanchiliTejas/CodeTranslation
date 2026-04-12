#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,q;
  cin>>n>>q;
  vector<Int> as(q),bs(q);
  for(Int i=0;i<q;i++) cin>>as[i]>>bs[i];

  vector<Int> vs(n+2,0);
  vs[1]=2;
  Int cur=1;
  for(Int i=0;i<q;i++){
    vs[cur-1]=vs[cur+1]=1;
    swap(vs[as[i]],vs[bs[i]]);
    if(vs[as[i]]==2) cur=as[i];
    if(vs[bs[i]]==2) cur=bs[i];
    vs[cur-1]=vs[cur+1]=1;
  }


  Int ans=0;
  for(Int i=1;i<=n;i++)
    ans+=vs[i]>=1;
  cout<<ans<<endl;
  return 0;
}
