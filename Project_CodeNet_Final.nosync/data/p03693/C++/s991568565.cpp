#include <iostream>
using namespace std;

int main() {
  int r,g,b;
  cin >> r >> g >> b;
  int ra = r *100;
  int ga = g *10;
  int k = ra + ga + b;
  if(k%4 == 0) cout << "YES" <<endl;
  else cout << "NO" <<endl;
}
