#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
  int A, B, C;
  long long X, Y, ans = 0;
  cin >> A >> B >> C >> X >> Y;
  if(A+B > C * 2){
    ans += C * min(X, Y) * 2;
  }
  else{
    ans += (A + B) * min(X, Y);
  }
  if(X > Y){
    ans += min(A * (max(X, Y) - min(X, Y)), C * (max(X, Y) - min(X, Y)) * 2);
  }
  else{
    ans += min(B * (max(X, Y) - min(X, Y)), C * (max(X, Y) - min(X, Y)) * 2);
  }
  cout << ans << endl;
  return 0;
}