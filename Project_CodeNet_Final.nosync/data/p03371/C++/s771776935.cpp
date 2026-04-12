#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <set>
using namespace std;
int main(void){
    int a,b,c,x,y,ans=0; cin>>a>>b>>c>>x>>y;
  	if(c*2<a+b){
      for(int i=0;i<min(x,y);i++){
        ans+=2*c;
      }
      if(max(x,y)==x){
        if(c*2<a) ans+=2*c*(x-y);
        else ans+=a*(x-y);
      }else{
        if(c*2<b) ans+=2*c*(y-x);
        else ans+=b*(y-x);
      }
    }else{
      ans=a*x+b*y;
    }
  	cout<<ans<<endl;
    return 0;
}