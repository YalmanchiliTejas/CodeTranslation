#include <bits/stdc++.h>
 
using namespace std;

int main(){
  int r,g,b;
  cin >> r >> g >> b;
  g = 10*g+b;
  if(g%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
