#include<bits/stdc++.h>
#define int long long
#define Inf 1000000000LL
using namespace std;
signed main(){
  int a,b,c,x,y,n,m;
  cin>>a>>b>>c>>x>>y;
  if(a+b<c*2){
    cout<<x*a+y*b<<"\n";
  }else{
    n = c*(max(x,y)*2);
    m = c*(min(x,y)*2);
    if(y<x){
      m+=(a*(x-y));
    }else{
      m+=(b*(y-x));
    }
    if(n<m){
      cout<<n<<"\n";
    }else{
      cout<<m<<"\n";
    }
  }
}