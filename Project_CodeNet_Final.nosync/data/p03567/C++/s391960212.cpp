#include <iostream>
#include <string>
#define ll long long
using namespace std;

string s;
void solve() {
  if (s.find("AC") == string::npos) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}

int main() {
  cin >> s;

  solve();
  return 0;
}
