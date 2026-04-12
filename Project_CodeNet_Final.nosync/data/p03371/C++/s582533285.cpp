//A.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int Ans = 0;
  int minA = min(X,Y);
  if(A+B>=2*C){
    Ans += 2*C*minA;
    X = X - minA;
    Y = Y - minA;
    if(X>0){
      if(A>=2*C){
        Ans += 2*X*C;
      }else{
        Ans += A*X;
      }
    }else{
      if(B>=2*C){
        Ans += 2*Y*C;
      }else{
        Ans += B*Y;
      }
    }
  }else{
    Ans += A*X + B*Y;
  }

  printf("%d\n",Ans);
  return 0;
}
