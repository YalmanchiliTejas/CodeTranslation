#include <iostream>
using namespace std;
int main(void){
  int r,g,b;
  cin >> r >> g >> b;
  int total = 100*r+10*g+b;
  if(total%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
