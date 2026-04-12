#include<iostream>
using namespace std;
 
int main(){
  int A, B, C;
  int X, Y;
 
  cin >> A >> B >> C >> X >> Y;
 
  unsigned long long cost;
 
  if(2*C >= A+B){
    cost = A*X + B*Y;
  }
 
  else if (2*C <= A && 2*C <= B ){
    if (X<=Y) cost = 2*C*Y;
    else cost = 2*C*X;
  }

  else if (2*C>A && 2*C>B && 2*C<A+B){
    if(X<Y) cost = 2*C*X + B*(Y-X);
    else cost = 2*C*Y + A*(X-Y);
  }
 
  else if (A<B){
    if(Y>=X) cost = 2*C*Y;
    else cost = 2*C*Y + A*(X-Y);
  }
  else {
    if (X>=Y) cost = 2*C*X;
    else cost = 2*C*X + B*(Y-X);
  }
 
  cout << cost;
 
 
  return 0;
}