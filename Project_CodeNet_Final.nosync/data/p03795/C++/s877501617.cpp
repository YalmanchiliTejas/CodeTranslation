#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, y;
  cin >> n;
  if (n < 15) {
    y = 0;
  } else {
    y = (n / 15) * 200;
  }

  cout << n * 800 - y << endl;
}