#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int money = 0;
  
  if (A+B >= 2*C){
    if (X > Y){
      money += C * 2 * Y;
      if (A <= C*2){
        money += A * (X - Y);
      }
      else {
        money += C * 2 * (X - Y);
      }
    }
    else if (X == Y){
      money += C * 2 * Y;
      cout << money << endl;
      return 0;
    }
    else if (X < Y){
      money += C * 2 * X;
      if (B <= C*2){
        money += B * (Y - X);
      }
      else {
        money += C * 2 * (Y - X);
      }
    }
  }
  else {
    money += A * X + B * Y;
  }
  cout << money << endl;
}
 
      

