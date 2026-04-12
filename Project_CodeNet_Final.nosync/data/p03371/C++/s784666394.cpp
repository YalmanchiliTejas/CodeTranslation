#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  int ans0=1e9;
  ans0=A*X+B*Y;
  int ans1=1e9;
  int ans2=1e9;
  if(X>Y) {
  ans1=A*(X-Y)+C*2*Y;
  }
  else {
  ans2=B*(Y-X)+C*2*X;
  }
  int ans3=1e9;
  ans3=C*max(X, Y)*2;
  int ans;
  ans=min({ans0, ans1, ans2, ans3});
  cout << ans << endl;
}