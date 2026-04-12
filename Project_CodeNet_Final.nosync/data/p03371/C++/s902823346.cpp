#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int K;//鐘
  
  if(A + B > 2 * C){//すくないのの枚数分*2はCにする
    if(X > Y){//Aの値段が2Cより高いならCで組み替えてしまえ
      if(A > 2 * C){
        K = 2 * C * X;
      }
      else{
        K = 2 * Y * C + A * (X - Y);
      }
    }
    else{//Y <= X,
      if(B > 2 * C){
        K = 2 * C * Y;
      }
      else{
        K = 2 * X * C + B * (Y - X);
      }
    }
  }
  else{//Cなんか必要ねえ
    K = A * X + B * Y;
  }
  
  cout << K << endl;
}