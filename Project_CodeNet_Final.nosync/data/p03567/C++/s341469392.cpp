#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int a = s.find("AC");
  if (a != string::npos) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}