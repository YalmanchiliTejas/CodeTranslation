#include <iostream>

using namespace std;

int main() {

  string input;

  cin >> input;

  char firstLetter = input[0];
  bool bDiff = false;

  for(int i = 1; i < 3; i++) {
    if (firstLetter != input[i]) {
      cout << "Yes" << endl;
      bDiff = true;
      break;
    }
  }

  if (bDiff == false) cout << "No" << endl;

  return 0;
}
