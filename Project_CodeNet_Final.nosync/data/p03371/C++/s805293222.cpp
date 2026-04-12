#include <iostream>

using namespace std;
int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  
  int ans = A*X + B*Y;
  
  if(X>Y){
    if(C*X*2 < ans)  ans = C*X*2;
    if(C*Y*2 + A*(X-Y) < ans) ans = C*Y*2 + A*(X-Y);}
  else {
    if(C*Y*2 < ans)  ans = C*Y*2;
    if(C*X*2 + B*(Y-X) < ans) ans = C*X*2 + B*(Y-X);}
  
  cout << ans;
}