#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int Z=0;
  if(2*C>=A+B){
    Z=A*X+B*Y;
  }
  else if(X>Y&&A<2*C){
    Z=C*Y*2+(X-Y)*A;
  }
  else if(X<Y&&B<2*C){
    Z=C*X*2+(Y-X)*B;
  }
  else{
    Z=C*2*max(X,Y);
  }
  cout<<Z<<endl;
}