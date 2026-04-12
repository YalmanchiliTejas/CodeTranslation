#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  int r, g, b;
  cin >> r >> g >> b;
  int s = 100*r + 10*g + b;
  if (s%4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}