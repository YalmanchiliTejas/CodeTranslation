#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,X,Y;
  cin >> A>>B>>C>>X>>Y;
  if(A+B>2*C){
    if(X>Y){
      cout<<min(max(X,Y)*C*2,Y*C*2+(X-Y)*A)<<endl;
    }
    else{
      cout<<min(max(X,Y)*C*2,X*C*2+(Y-X)*B)<<endl;
    }
  }
  else{
    cout<<min(max(X,Y)*C*2,A*X+B*Y)<<endl;
  }
}