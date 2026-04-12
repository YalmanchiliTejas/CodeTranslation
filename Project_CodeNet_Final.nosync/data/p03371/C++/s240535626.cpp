#include <bits/stdc++.h>

using namespace std;

int main(){
  int A,B,C,X,Y;
  long long int F=0;
  cin >> A >> B >> C >> X >> Y;
  if(A+B<=2*C){
    F+=A*X;
    F+=B*Y;
  }else if(A+B>2*C){
    while((X>=1) && (Y>=1)){
      F+=2*C;
      X--;Y--;
    }
    while(X>0){
      if(A>2*C){F+=2*C;}
      else{F+=A;}
      X--;
    }
    while(Y>0){
      if(B>2*C){F+=2*C;}
      else{F+=B;}
      Y--;
    }
  }
  cout << F << endl;
  return 0;
}
