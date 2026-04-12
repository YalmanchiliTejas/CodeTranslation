#include <bits/stdc++.h>
using namespace std;

int main() {
 
  int r, b, g;
  cin >> r >> b >> g;

  int sum = r * 100 + b * 10 + g;

  if (sum % 4 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

}