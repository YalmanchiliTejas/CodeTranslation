#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;

  int ans = X / (Y + Z);
  if(X % (Y + Z) < Z) {
    cout << X / (Y + Z) - 1;
  } else {
    cout << X / (Y + Z);
  }
  return 0;
}

