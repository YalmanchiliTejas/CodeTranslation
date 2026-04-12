#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define BIG 1000000010
#define EPS 1e-9
#define first fst
#define second scd

#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long


signed main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  if(a+b<c*2){
    cout<<(a*x)+(b*y)<<endl;
  }
  else{
    int ans=0;
    ans+=(min(x,y)*c*2);
    if(x>y) ans+=(x-y)*min(a,c*2);
    else ans+=(y-x)*min(b,c*2);
    cout<<ans<<endl;
  }
  

  return 0;
}
