#include <bits/stdc++.h>
using namespace std;

signed main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int D;
  if(max(X,Y)==X){
    D=A*(X-Y);
  }
  else{
    D=B*(Y-X);
  }
  if(A*X+B*Y<C*max(X,Y)*2&&A*X+B*Y<C*min(X,Y)*2+D){
    cout << A*X+B*Y << endl;
  }
  else{
    if(2*C*max(X,Y)>2*C*min(X,Y)+D){
      cout << 2*C*min(X,Y)+D << endl;
    }
    else{
      cout << 2*C*max(X,Y) << endl;
    }
  }
}
