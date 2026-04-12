#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  if (S.find("AC") != S.npos) cout << "Yes" << endl; else cout << "No" << endl;
}