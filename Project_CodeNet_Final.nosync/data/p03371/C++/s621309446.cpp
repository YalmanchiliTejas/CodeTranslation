#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int ans;
  if (X>Y){
    ans=min(min(A*X+B*Y,C*2*Y+A*(X-Y)),C*2*X);
  }
  else {
    ans=min(min(A*X+B*Y,C*2*X+B*(Y-X)),C*2*Y);
  }
  cout << ans << endl;
}