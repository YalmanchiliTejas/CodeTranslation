#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
  int a,b,c,x,y,m;
  cin>>a>>b>>c>>x>>y;
  int ans=0;
  if(x>y){
    swap(x,y);
    swap(a,b);
  }
  if(a+b<=2*c){
    ans=a*x+b*y;
    cout<<ans<<endl;
    return 0;
  }
  ans+=2*c*x;
  if(b<=2*c){
    ans+=b*(y-x);
  }else{
    ans+=2*c*(y-x);
  }
  cout<<ans<<endl;
  return 0;
}
