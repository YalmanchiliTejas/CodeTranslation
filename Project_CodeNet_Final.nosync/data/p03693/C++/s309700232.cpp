#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, g, b;
  int R, G, S;
  cin >> r >> g >> b;
  R=r*100;
  G=g*10;
  S=R+G+b;
  
  if(S%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;  
  return 0;
}