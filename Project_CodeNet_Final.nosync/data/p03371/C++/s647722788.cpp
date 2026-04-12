#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main(){
  int a,b,c,x,y,i,m,ans=0,ans_max=0,res,res_pay;

  std::cin >> a>>b>>c>>x>>y;

  int x_0=x;
  int y_0=y;

  if(2*c<=a+b){
    m=max(x,y);
    for(i=0;i<m;i++){
      ans_max=ans_max+(c*2);
    }
    m=min(x,y);
    for(i=0;i<m;i++){
      ans=ans+(c*2);
      x=x-1;
      y=y-1;
    }
    if(x>y){
       res=x;
       
       res_pay=a;
     }

    else if(x<y) {
      res=y;
      res_pay=b;
    }

    for(i=0;i<res;i++){
      ans=ans+res_pay;
    }

    if(ans_max<ans){
      ans=ans_max;
    }
  }

  else{
    for(i=0;i<x_0;i++){
      ans=ans+a;
    }
    for(i=0;i<y_0;i++){
      ans=ans+b;
    }
  }

  std::cout << ans << '\n';


return 0;


}
