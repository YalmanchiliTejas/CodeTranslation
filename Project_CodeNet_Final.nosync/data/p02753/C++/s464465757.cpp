#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  char c = S.at(0);
  bool can = true;
  if (c == S.at(1) && c == S.at(2)) can = false;
  
  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}