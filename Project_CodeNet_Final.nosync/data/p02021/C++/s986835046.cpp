#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];

  Int ans=0;
  for(Int x=1;x<=200;x++){
    Int res=0,ok=1;
    for(Int i=0;i<n;i++){
      res+=a[i];
      res-=x;
      if(res<0) ok=0;
    }
    if(ok) ans=x;
  }
  cout<<ans<<endl;
  return 0;
}

