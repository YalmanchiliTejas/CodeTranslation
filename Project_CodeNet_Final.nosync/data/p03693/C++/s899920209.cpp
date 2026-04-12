#include <iostream>
using namespace std;

int main(){
  int n, r, g, b;
  cin >> r >> g >> b;
  n = int(r)*100 + int(g)*10 + int(b);
  if ( n%4==0 ){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}
 