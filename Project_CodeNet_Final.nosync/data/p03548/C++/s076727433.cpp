#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;

  cout << (X - Z) / (Y + Z) << endl;
  return 0;
}