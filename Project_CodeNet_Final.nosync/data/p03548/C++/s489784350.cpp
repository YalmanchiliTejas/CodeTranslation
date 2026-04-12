#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  Int x,y,z;
  cin>>x>>y>>z;
  Int l=0,r=1e9;
  while(l+1<r){
    Int m=(l+r)>>1;
    if(m*y+(m+1)*z<=x) l=m;
    else r=m;
  }
  cout<<l<<endl;
  return 0;
}
