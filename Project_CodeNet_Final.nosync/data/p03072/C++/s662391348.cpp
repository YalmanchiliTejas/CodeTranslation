#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> h(n);
  for(Int i=0;i<n;i++) cin>>h[i];
  Int ans=0;
  for(Int i=0;i<n;i++){
    Int flg=1;
    for(Int j=0;j<i;j++) if(h[j]>h[i]) flg=0;
    ans+=flg;
  }
  cout<<ans<<endl;
  return 0;
}
