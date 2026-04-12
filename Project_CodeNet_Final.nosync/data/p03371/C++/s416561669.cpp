#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;



int main (){
  int a,b,c,x,y;
  int sum = 0;

  cin >>a>>b>>c>>x>>y;

  if (x > y){
    if((a+b) > 2*c){
      sum += 2*c*y;
      if(a < c*2){
      sum += a*(x-y);
    }else{
      sum += c*2*(x-y);
    }
    }else{
      sum += a*x+b*y;
    }

  }else{
    if((a+b) > 2*c){
      sum += 2*c*x;
      if(b < c*2){
      sum += b*(y-x);
    }else{
      sum += c*2*(y-x);
    }
    }else{
      sum += a*x+b*y;
    }

  }


  std::cout << sum << '\n';


  return 0;


}
