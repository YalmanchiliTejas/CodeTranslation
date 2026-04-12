#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  if(A + B > C*2){
    if(Y < X){
      swap(A,B);
      swap(X,Y);
    }
    int res = C * 2 * X;
    Y -= X;
    if(B > C*2){
      res += C * 2 * Y;
    }
    else {
      res += B * Y;
    }
    cout << res << endl;
  }
  else {
    cout << X*A + Y*B << endl;
  }
  return 0;
}
