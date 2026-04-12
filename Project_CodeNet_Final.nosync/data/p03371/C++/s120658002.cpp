#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int sumA=0;
  int sumB=0;
  if(A+B<=C*2){
    sumA=A*X+B*Y;
    sumB=A*X+B*Y;
  }else{
    if(X>Y){
      sumA=C*X*2;
      sumB=C*Y*2+A*(X-Y);
    }else{
      sumA=C*Y*2;
      sumB=C*X*2+B*(Y-X);
    }
  }
  cout << min(sumA,sumB) << endl;
  return 0;
}
