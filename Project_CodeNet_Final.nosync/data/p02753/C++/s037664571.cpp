#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  char c1; cin >> c1;
  char c2; cin >> c2;
  char c3; cin >> c3;
  if (c1 != c2 || c1 != c3) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
