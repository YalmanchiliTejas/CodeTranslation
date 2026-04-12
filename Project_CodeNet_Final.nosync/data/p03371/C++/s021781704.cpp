#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C,x,y;
  cin >> A >> B >> C >> x >> y;
  //枚数の多いほうがA円X枚
  if(x < y){
    int tmp = A;
    A = B;
    B = tmp;
    tmp = x;
    x = y;
    y = tmp;
  }
  
  bool ab,ac,bc;
  ab = ac = bc = false;
  if(A+B > 2*C) ab = true;
  if(A > 2*C) ac = true;
  if(B > 2*C) bc = true;
  if(ab == true){
    if(ac == true) cout << 2*C*x << endl;
    else cout << 2*C*y + A*(x-y) << endl;
  }else{
    cout << A*x + B*y << endl;
  }
}
