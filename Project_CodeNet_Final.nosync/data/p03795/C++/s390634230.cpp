#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x,y;
  cin >> n;
  x = 800*n;
  n = n/15;
  y = 200*n;
  cout << x - y << endl;
  return 0;
}
