#include <iostream>
using namespace std;

int main() {
  char a, b, c;
  cin >> a >> b >> c;
  if(a == b && a == c) {
    cout << "No";
  } else {
    cout << "Yes";
  }
}
