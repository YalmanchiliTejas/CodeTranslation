#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C,X,Y,Z;
  cin>>A>>B>>C>>X>>Y;
  if(X>Y){
    int Z=X-Y;
    cout<<min((A*X)+(B*Y),min(C*X*2,(C*Y*2)+(A*Z)))<<endl;
  }else if(Y>X){
    int Z=Y-X;
    cout<<min((A*X)+(B*Y),min(C*Y*2,(C*X*2)+(B*Z)))<<endl;
  }else{
    cout<<min((A*X)+(B*Y),C*Y*2)<<endl;
  }
  return 0;
}

