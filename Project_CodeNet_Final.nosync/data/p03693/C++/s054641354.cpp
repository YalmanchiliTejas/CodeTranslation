#include <iostream>
using namespace std;

int main() {
  int ans = 0;
  int c;
  for(int i = 0; i < 3; ++i) {
    cin >> c;
    ans = 10 * ans + c;
  }
  if(ans % 4 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}