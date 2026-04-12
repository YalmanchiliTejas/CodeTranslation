#include<bits/stdc++.h>
using namespace std;

int main () {
  string S;
  cin >> S;
  
  bool ans = false;
  for (int i = 0; i < S.size() - 1; i++) {
    if (S.at(i) == 'A') {
      if (S.at(i + 1) == 'C') {
        ans = true;
      }
    }
  }
  if (ans) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}