#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x,y,ans=0;cin>>a>>c>>b>>x>>y;b*=2;
  if(x<y){
    a^=c;c^=a;a^=c;
    x^=y;y^=x;x^=y;
  }
  while(y){
    ans+=min(a+c,b);
    x--;y--;
  }
  while(x){
    ans+=min(a,b);
    x--;
  }
  cout<<ans<<endl;
}