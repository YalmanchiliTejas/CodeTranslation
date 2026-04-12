#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, C, X, Y;
  int Ap, Bp, Cp;
  cin >> A >> B >> C >> X >> Y;
  Ap = 0; Bp = 0; Cp = 0;

       if(A + B > 2 * C){
       if(X < Y){
       Cp = 2 * X;
          if(B >= 2 * C){
          Cp = Cp + (Y - X) * 2;
          }
          else{
          Bp = Y - X;
          }
       } 
       else{
       Cp = 2 * Y;
          if(A >= 2 * C){
          Cp = Cp + (X - Y) * 2;
          }
          else{
          Ap = X - Y;
          }
       }
    }
    else{
    Ap = X;
    Bp = Y;
    }
    
    cout << Ap * A + Bp * B + Cp * C << endl;
}
