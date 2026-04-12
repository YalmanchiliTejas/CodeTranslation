#include <iostream>
using namespace std;

int main(){

  int r,g,b;
  cin >> r >> g >> b;
  int niketa = g*10+b;

  if(niketa % 4 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
