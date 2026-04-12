#include <iostream>

using namespace std;

int main(){

  int A,B,C,X,Y;
  long long int sum,left,ans1,ans2;
  long long int min = 500000000;
  
  cin >> A >> B >> C >> X >> Y;

  ans1 = A*X + B*Y;
  if(X < Y){
    sum = C * X * 2;
    left = Y - X;
    for(int i = 0; i <= left; i++){
      int left_sum = i * B + (left - i) * C * 2;
      if(left_sum < min){
	min = left_sum;
      }
    }
    ans2 = sum + min;
  }
  else{
    sum = C * Y * 2;
    left = X - Y;
    for(int i = 0; i <= left; i++){
      int left_sum = i * A + (left - i) * C * 2;
      if(left_sum < min){
	min = left_sum;
      }
    }
    ans2 = sum + min;
  }

  if(ans1 < ans2){
    cout << ans1 << "\n";
  }
  else{
    cout << ans2 << "\n";
  }
  
  return 0;

}
