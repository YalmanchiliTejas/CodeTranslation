#include <iostream>
 
using namespace std;
 
int main() {
  string s = "";
  cin >> s;
  int a = 0;
  int b = 0;
  for (int i = 0; i < 3; i++) {
    if (s[i] == 'A') {
      a = 1;
    } else if (s[i] == 'B') {
      b = 1;
    }
  }
  
  if (a == 1 && b == 1) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  
  return 0;
}