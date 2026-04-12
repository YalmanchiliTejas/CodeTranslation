#include<bits/stdc++.h>
using namespace std;

int main() {
  int r,g,b,num;
  cin >> r >> g >> b;
  num = 100*r + 10*g + b;
  if(num%4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}