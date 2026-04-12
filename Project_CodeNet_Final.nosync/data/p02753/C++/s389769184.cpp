#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  bool A, B;
  A = B = false;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'A') A = true;
    if (s[i] == 'B') B = true;
  }
  puts((A&B)?"Yes":"No");
  return 0;
}