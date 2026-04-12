#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using us = unsigned short;

int main (void){
  us r, g, b;
  cin >> r >> g >> b;

  us num;
  num = g * 10 + b;
  if(num % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
