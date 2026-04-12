#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int64_t money = 0;
  if(A+B > C*2){
    money += min(X,Y)*C*2;
    int64_t orX = X;
    X -= min(X,Y);
    Y -= min(orX,Y);
  }
  if(max(X,Y)*C*2 < A*X+B*Y){
    money += max(X,Y)*C*2;
  }
  else{
    money += A*X+B*Y;
  }
  cout << money << endl;
}