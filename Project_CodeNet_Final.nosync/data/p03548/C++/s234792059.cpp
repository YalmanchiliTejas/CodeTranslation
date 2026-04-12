#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int ans = 0, num = Z;
  while (num<=X) {
    ans++;
    num += Y+Z;
  }
  cout << ans-1 << endl;
}