#include <iostream>
using namespace std;

int main(){
  int r,g,b;
  cin >> r  >> g  >> b;
  r *= 100;
  g *= 10;
  int i = r + g + b;

  if (i % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}