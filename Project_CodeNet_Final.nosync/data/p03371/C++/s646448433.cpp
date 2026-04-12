#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y; cin>>a>>b>>c>>x>>y;
  long long ans=0;
  if(x<y){
    ans+=min(a+b,c*2)*x;
    y-=x;
    ans+=min(b,c*2)*y;
  }else{
    ans+=min(a+b,c*2)*y;
    x-=y;
    ans+=min(a,c*2)*x;
  }
  cout<<ans<<endl;
}