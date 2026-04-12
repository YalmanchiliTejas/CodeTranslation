#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int a = 0, b = 0;
  for (char ch : s) {
    if (ch == 'A') ++a;
    else ++b;
  }
  if (a && b) {
   cout << "Yes\n";
  } else {
   cout << "No\n";
  }
}