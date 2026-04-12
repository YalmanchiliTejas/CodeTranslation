#include <iostream>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;

  char c = S[0];
  for (int i = 1; i < 3; i++) {
    if (c != S[i]) {
      cout << "Yes" << endl;
      return 0;
    }
    c = S[i];
  }
  cout << "No" << endl;

  return 0;
}
