#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, X, Y, price = 0;
  cin >> A >> B >> C >> X >> Y;
  price = min(X, Y) * min(A+B, C*2);
  if(X < Y){
  	price += (Y - X) * min(B, C*2);
  }else if(X > Y){
  	price += (X - Y) * min(A, C*2);
  }
  cout << price << endl;
  return 0;
}