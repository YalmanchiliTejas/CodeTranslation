#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  cout << (s.find("AC") != string::npos ? "Yes" : "No") << endl;
}