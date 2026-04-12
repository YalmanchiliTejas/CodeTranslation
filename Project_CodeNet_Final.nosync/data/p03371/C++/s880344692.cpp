#include <bits/stdc++.h>
using namespace std;

int main(){
  long long A,B,C,X,Y,ansA,ansB,ansC;
  cin >> A >> B >> C >> X >> Y;
  if(X>Y){
    ansA=2*C*X;
    ansB=2*C*Y+A*(X-Y);
    ansC=A*X+B*Y;
  }
  else{
    ansA=2*C*Y;
    ansB=2*C*X+B*(Y-X);
    ansC=A*X+B*Y;
  }
  cout << min(ansA,min(ansB,ansC)) << endl;
}