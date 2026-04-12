#include <iostream>
using namespace std;
int main(void) {
  char s[3];
  cin >> s;
  if(s[0] == s[1]) {
    if(s[1] != s[2]) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  else {
    cout << "Yes" << endl;
  }
  return 0;
}