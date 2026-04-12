#include <iostream>
using namespace std;

int main() {
  int n;

  while (cin >> n) {
    if (n == 7 || n == 5 || n == 3) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
