#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C;
  long X, Y;
  cin >> A >> B >> C >> X >> Y;
  long cost=1e9;
  if(cost>2*C*max(X,Y)){
    cost = 2*C*max(X,Y);
  }
  if(X>=Y && cost>2*C*Y+A*(X-Y)){
    cost = 2*C*Y+A*(X-Y);
  }
  if(X<Y && cost>2*C*X+B*(Y-X)){
    cost = 2*C*X+B*(Y-X);
  }
  if(cost>A*X+B*Y){
    cost = A*X+B*Y;
  }
  cout << cost << endl;
  return 0;
}