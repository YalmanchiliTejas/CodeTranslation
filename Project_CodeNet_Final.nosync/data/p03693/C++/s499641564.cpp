#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int r, g, b;
  cin >> r >> g >> b;
  
  r *= 100;
  g *= 10;
  
  int N = r + g + b;
  
  if ( N % 4 == 0 ) cout << "YES" << endl;
  if ( N % 4 != 0 ) cout << "NO" << endl;
  
}