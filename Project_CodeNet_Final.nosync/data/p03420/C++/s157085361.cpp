#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n,k;
  cin>>n>>k;
  if(k==0){
    cout<<n*n<<endl;
    return 0;
  }
  Int ans=0;
  for(Int b=k+1;b<=n;b++){
    Int l=0,r=n+1;
    while(l+1<r){
      Int m=(l+r)>>1;
      if(b*m-1<=n) l=m;
      else r=m;
    }
    //cout<<b<<" "<<l<<" "<<r<<endl;
    ans+=(b-k)*l;
    Int x=n-(b*l+k)+1;
    if(x>=0) ans+=x;
  }
  cout<<ans<<endl;
  return 0;
}
