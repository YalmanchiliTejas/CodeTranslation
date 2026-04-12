#include <iostream>
using namespace std;

int main(){
 int r,g,b;
  cin >> r >> g >> b;
  int d = 100*r;
  int e = 10*g;
  int f = d + e + b;
  if(f % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}
