#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main(){
  
  ll A,B,C,X,Y,a,b,c,d,e,f,g;
  
  cin>>A>>B>>C>>X>>Y;
  a=A*X+B*Y;
  if(X>Y){
    
    b=C*2*X;
    c=C*2*Y+A*(X-Y);
    d=C*2*X;
    
  }else{
    
    b=C*2*Y;
    c=C*2*X+B*(Y-X);
    d=C*2*Y;
    
  }
  
  cout<<min(min(a,b),min(c,d))<<endl;
  
  return 0;
}