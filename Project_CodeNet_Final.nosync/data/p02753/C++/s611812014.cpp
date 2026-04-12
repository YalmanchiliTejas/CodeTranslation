#include <bits/stdc++.h>

using namespace std;

int main() {
  string S;
  char c = -1;
  bool ans = false;
  
  cin >> S;
  
  c = S.at(0);
  
  for (int i = 0; i < 3; i++) {
    if (c != S.at(i)) {
      ans = true;
    }
  }
  
  cout << (ans ? "Yes" : "No") << endl;
  
  return 0;
}