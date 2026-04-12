#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int sum = 0;
  int min = A * X + B * Y;
  for(int i = 0; i <= 100000; i++) {
    sum = 2 * C * i + max( X - i , 0 ) * A + max( Y - i, 0 ) * B;
    if(min > sum) min = sum;
  }

  cout << min; 
  return 0;
}