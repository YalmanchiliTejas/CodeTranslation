#include <bits/stdc++.h>

using namespace std;

int main () {

  int X;
  cin >> X;

  bool ans;

  if (X == 3 || X == 5 || X == 7) {
    ans = true;
  } else {
    ans = false;
  }

  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }


  return 0;
}