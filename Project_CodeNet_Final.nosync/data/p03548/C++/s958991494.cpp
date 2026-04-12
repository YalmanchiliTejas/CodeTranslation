#include <bits/stdc++.h>
using namespace std;
int main() {
int X,Y,Z;
cin >> X >> Y >> Z;
int cnt = Z,ans = 0;;
while (ans <= X) {
  cnt += Y+Z;
  if (cnt > X) break;
  ans++;
}
cout << ans << endl;

return 0;
}