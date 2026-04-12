#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  bool ac = false;
  for (int i = 0; i < s.size() - 1; ++i) {
    string sub = s.substr(i, 2);
    if (sub == "AC")
      ac = true;
  }

  if (ac)
    puts("Yes");
  else
    puts("No");
}