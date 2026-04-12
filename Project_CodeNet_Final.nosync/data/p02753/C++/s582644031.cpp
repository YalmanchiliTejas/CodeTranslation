#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  bool flag_a = false, flag_b = false;
  for (int i = 0; i < 3; i++) {
    if (S[i] == 'A') {flag_a = true;}
    if (S[i] == 'B') {flag_b = true;}
  }

  cout << ( flag_a && flag_b ? "Yes" : "No" ) << endl;
}
