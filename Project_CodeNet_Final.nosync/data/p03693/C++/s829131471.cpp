#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
  int r, g, b;
  cin >> r >> b >> g;
  
  if((10*b + g) % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  
}