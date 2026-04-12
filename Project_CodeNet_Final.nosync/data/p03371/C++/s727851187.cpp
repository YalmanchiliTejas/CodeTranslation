#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,Y,cost1,cost2,cost3;
  cin >> A >> B >> C >> X >> Y;
  
  cost1=A*X+B*Y;
  cost2=2*C*max(X,Y);
  if(X<=Y){
    cost3=2*C*X+B*(Y-X);
  }
  else{
    cost3=2*C*Y+A*(X-Y);
  }
  cout << min({cost1,cost2,cost3}) << endl;
} 