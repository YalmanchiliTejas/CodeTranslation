#include <iostream>
using namespace std;
int main() {
  int N;
  cin >> N;
  switch(N) {
  case 3:
  case 5:
  case 7:
    cout << "YES" << endl;
    break;
  default:
    cout << "NO" << endl;
    break;
  }
  return 0;
}