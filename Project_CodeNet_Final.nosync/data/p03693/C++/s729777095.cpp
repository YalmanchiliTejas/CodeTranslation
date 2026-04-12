#include <iostream>
#include <string>
using namespace std;

int main() {
  int a, b,c;
  int flag =0;;
  cin >> a >> b >> c;
  if((10 * b + c)%4 ==0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}