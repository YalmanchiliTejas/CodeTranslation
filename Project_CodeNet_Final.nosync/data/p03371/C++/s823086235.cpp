#include <bits/stdc++.h>
using namespace std;
int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  if(A+B <= 2*C){
    cout << A*X+B*Y << endl;
  }else{
    if(X<=Y){
      if(2*C <= B){
        cout << 2*C*Y << endl;
      }else{
        cout << 2*C*X+(Y-X)*B << endl;
      }
    }else{
      if(2*C <= A){
        cout << 2*C*X << endl;
      }else{
        cout << 2*C*Y+(X-Y)*A << endl;
      }
    }
  }
}