#include <iostream>
using namespace std;
int main() {
  int r,g,v;
  cin >> r >> g >> v;
  int a = g*10 + v;
  if (a%4 == 0)
    cout << "YES" << endl;
  else
    cout << "NO"  << endl;
}