#include <iostream>

using namespace std;

int main(){
  int r, g, b;
  cin >> r;
  cin >> g;
  cin >> b;
  int sum = 10 * g + b;
  if (sum % 4 == 0) {
    cout << "YES";
  }
  else {
    cout << "NO";
  }
  return 0;
}
