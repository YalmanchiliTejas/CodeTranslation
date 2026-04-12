#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int sum1, sum2, sum3;

  sum1 = A * X + B * Y;

  if(X > Y){
    sum2 = 2 * C * Y + A * (X - Y);
    sum3 = 2 * C * X;
  }else{
    sum2 = 2 * C * X + B * (Y - X);
    sum3 = 2 * C * Y;
  }

  int sum[3] = {sum1, sum2, sum3};

  sort(sum, sum + 3);

  cout << sum[0] << endl;
}
