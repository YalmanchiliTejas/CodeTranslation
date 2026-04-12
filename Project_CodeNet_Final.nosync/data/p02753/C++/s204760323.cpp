#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  char ch = str[0];
  cout << ((str[1] == ch && str[2] == ch) ? "No" : "Yes") << endl;
  return 0;
}