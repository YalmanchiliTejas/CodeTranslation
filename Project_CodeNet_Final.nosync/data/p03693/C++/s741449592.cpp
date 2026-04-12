#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int num = a * 100 + b * 10 + c;
  if(num % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}