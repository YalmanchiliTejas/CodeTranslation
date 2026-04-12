#include <bits/stdc++.h>
//#include <string>
using namespace std;
int main() {
  string S;
  cin >> S;
  bool allA = true;
  bool allB = true;
  for (int i=0; i < 3; i++) {
    if (S[i] == 'B')
      allA = false;
    if (S[i] == 'A')
      allB = false;
  }
  if (allA || allB) {
	cout << "No";
  }
  else 	cout << "Yes";
  return 0;
}