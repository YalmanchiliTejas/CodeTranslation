#include <bits/stdc++.h>

using namespace std;

int main(void) {
  string s;
  cin >> s;
  
  bool f_a = false, f_b = false;
  
  for (int i = 0; i < 3;i++) {
    if (s[i] == 'A') f_a = true;
    else f_b = true;
  }
  
  if (f_a & f_b) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}