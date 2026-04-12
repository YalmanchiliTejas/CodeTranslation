#include<iostream>
using namespace std;
int main () {
  int a, b, c;
  char k, m, d;
  cin >> k >> m >> d;
  a = ((k == 'A') ? 0 : 1);
  b = ((m == 'A') ? 0 : 1);
  c = ((d == 'A') ? 0 : 1);
  int an = a + b + c;
  if (an == 0 || an == 3) cout << "No" << endl;
  else cout << "Yes" << endl;
}
