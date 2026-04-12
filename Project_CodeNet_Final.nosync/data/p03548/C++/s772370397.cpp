#include<bits/stdc++.h>
using namespace std;

int main () {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  
  int a = Z, b = Y+Z, ans = 0;
  while (a+b <= X) {
    a += b;
    ans++;
  }
  cout << ans << endl;
}