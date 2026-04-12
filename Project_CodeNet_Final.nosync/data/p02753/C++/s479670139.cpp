#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  bool A = false, B = false;
  for (int i = 0; i < S.size(); i++) {
    if (S.at(i) == 'A') A = true;
    if (S.at(i) == 'B') B = true;
  }

  if (A && B) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
