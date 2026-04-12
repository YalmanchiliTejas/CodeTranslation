#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, y;
  cin >> n;
  
  x = 800*n;
  y = n/15;
  cout << x - 200*y << endl;
  return 0;
}