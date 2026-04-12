#include<iostream>
using namespace std;

int main(){
  int X, Y, Z;
  cin >> X >> Y >> Z;

  int oneWidth = Y + Z;
  int num = X / oneWidth;
  if( (X - num*oneWidth) < Z  )
    num--;
  cout << num << endl;
  return 0;
}
