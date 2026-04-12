#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int m=min(x,y);
  int ans;
  if(a+b<2*c){
    ans = (a+b)*m;
  }else{
    ans = 2*c*m;
  }
  
  x -= m;
  y -= m;
  
  if(x>0){
    if(a<2*c){
      ans += a*x;
    }else{
      ans += 2*c*x;
    }
  }
  
  if(y>0){
    if(b<2*c){
      ans += b*y;
    }else{
      ans += 2*c*y;
    }
  }

  cout<<ans<<endl;
  return 0;
}