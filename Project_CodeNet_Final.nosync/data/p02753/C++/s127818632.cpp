#include <iostream>
#include <string>

using namespace std;

int main () {
  string s;
  cin >> s;

  if (s == string("AAA") || s == string("BBB")) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
