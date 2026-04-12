#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  int a = 0, b = 0;
  for (int i = 0; i < 3; i++) {
    cin >> c;
    if (c == 'A')
      a++;
    else
      b++;
  }

  if (a == 0 || b == 0)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}