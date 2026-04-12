#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;

  
  int p = (X > Y)? A:B;
  int ans1 = C*2 * min(X,Y) + p * abs(X-Y); // 残り
  
  int ans2 = (A*X) + (B*Y);
  
  int ans3 = C*2 * max(X,Y);
  
  cout << min(min(ans1, ans2), ans3) << endl;
}