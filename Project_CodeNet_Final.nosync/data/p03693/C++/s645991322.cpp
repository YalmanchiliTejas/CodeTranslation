#include <iostream>
using namespace std;

int r,g,b;

int main(){
  cin >> r >> g >> b;
  int num;
  num = 100*r + 10*g + b;

  cout << (num % 4 == 0 ? "YES" : "NO") << endl;
  return 0;
}
