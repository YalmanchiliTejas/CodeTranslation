#include <iostream>
#include <vector>

using namespace std;

int main(){
  int A,B,C,X,Y; cin>>A>>B>>C>>X>>Y;

  int num0,num1,num2;

  if(X>Y){
    num0=2*Y*C+A*(X-Y);
    num2=2*X*C;
  }
  else{
    num0=2*X*C+B*(Y-X);
    num2=2*Y*C;
  }

  num1=A*X+B*Y;

  cout<<min(num0,min(num1,num2))<<endl;

  return 0;
}
