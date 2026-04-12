#include <iostream>
using namespace std;

int main(){
  int r,g,b;
  cin >> r >> g >> b;
  int A = 100*r +10*g + b;
  if(A%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;
}
