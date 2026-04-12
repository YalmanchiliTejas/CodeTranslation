#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  cout << ((s.find("AC") != string::npos) ? "Yes\n" : "No\n");
  return 0;
}

