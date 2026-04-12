#include<iostream>
#include<math.h>
using namespace std;

int main(){
  int A,B,C,X,Y;
  int ans=0;
  int h,l;
  cin>>A>>B>>C>>X>>Y;
  int s=abs(X-Y);
  if(A+B>C*2){
    if(X>Y){
      ans+=Y*C*2;
      ans+=(A<(C*2))?A*s:C*2*s;
    }
    else{
      ans+=X*C*2;
      ans+=(B<(C*2))?B*s:C*2*s;
    }
  }
  else{
    ans+=X*A+Y*B;

  }
  cout<<ans;
  return 0;
}