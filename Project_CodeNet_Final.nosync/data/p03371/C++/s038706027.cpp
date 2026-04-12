// ------------------
// author: MatsuTaku
// date  : 22/02/2020
// ------------------

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int A,B,C,X,Y; cin>>A>>B>>C>>X>>Y;
  int ans1 = A*X+B*Y;
  int ans2 = X>=Y ? A*(X-Y)+C*Y*2 : C*X*2+B*(Y-X);
  int ans3 = max(X,Y)*C*2;
  cout << min(min(ans1, ans2), ans3) << endl;

  return 0;
}
