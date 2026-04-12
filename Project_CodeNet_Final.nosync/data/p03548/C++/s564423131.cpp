#include <iostream>

using namespace std;

int main(){
  int a, b, c;
  int x = 0;
  cin >> a >> b >> c;
  a-= b + 2 * c;
  x++;
  x += a / (b + c);
  cout << x << endl;
  return (0);
}
