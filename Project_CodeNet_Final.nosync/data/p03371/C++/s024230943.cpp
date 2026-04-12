#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  if(A > B) {swap(A, B); swap(X, Y);}
  int ans;
  if(2 * C <= A) ans = 2 * C * max(X, Y);
  else if(2 * C <= B) ans = 2 * C * Y + A * max(X - Y, 0);
  else if(2 * C <= A + B) {
    if(X < Y) ans = 2 * C * X + (Y - X) * B;
    else ans = 2 * C * Y + (X - Y) * A;
  }else ans = A * X + B * Y;
  
  cout << ans << endl;
}