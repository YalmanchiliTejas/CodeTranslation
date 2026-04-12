#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

int main(){
  int A,B,C,X,Y;
  std::cin >> A >> B >> C >> X >> Y;

  int a=0,b=0,c=0;
  
  if((A+B)>(C*2)){
    if(X>Y){
      c = Y*2;
      X = X-Y;
      Y = 0;
      if(X*A<X*C*2){
	a = X;
      }else{
	c += X*2;
      }
    }else{
      c = X*2;
      Y = Y-X;
      X = 0;
      if(Y*B<Y*C*2){
	b = Y;
      }else{
	c += Y*2;
      }
    }
    //std::cout << a << b << c << std::endl;
  }else{
    a = X;
    b = Y;
  }

  std::cout << (a*A+b*B+c*C) << std::endl;
  return 0;
}
    
