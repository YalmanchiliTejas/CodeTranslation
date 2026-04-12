#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int A;
  int B;
  int C;
  int X;
  int Y;
  cin >> A >> B >> C >> X >> Y;
  
  int AB = min(X, Y);
  X -= AB;
  Y -= AB;
  int sum = 0;
  if(A + B < C * 2){
    sum += AB * (A + B);
  }else{
    sum += AB * (C * 2);
  }
  if(A < C*2){
    sum += X * A;
  }else{
    sum += X * (C * 2);
  }
  if(B < C*2){
    sum += Y * B;
  }else{
    sum += Y * (C * 2);
  }
  cout << sum;
  return 0;
}