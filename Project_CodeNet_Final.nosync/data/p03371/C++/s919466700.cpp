#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
  int a,b,c,x,y,ans=1000000000,e;
  cin>>a>>b>>c>>x>>y;
  for(int i=0;i<=max(x,y);i++){
    e=c*2*i+a*max(0,x-i)+b*max(0,y-i);
    ans=min(ans,e);
  }
  cout<<ans<<endl;
}
