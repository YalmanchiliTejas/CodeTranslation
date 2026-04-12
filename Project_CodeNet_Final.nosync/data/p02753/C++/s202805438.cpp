#include <iostream>
#include <string>

using namespace std;

int main() {
  string a;
  std::cin >> a;

  char t = a[0];

  bool exists = false;
  for (int i = 1; i < a.length(); i++) {
    if (a[i] != t) {
      exists = true;
      break;
    }
    t = a[i];
  }

  if (exists) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }


  return 0;
}
