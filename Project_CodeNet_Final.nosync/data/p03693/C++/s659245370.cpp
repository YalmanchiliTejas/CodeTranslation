#include <bits/stdc++.h>
using namespace std;

int main() {
  int r,g,b; cin >> r >> g >> b;
  int k = 10 * g + b;
  if (k % 4 == 0)
    cout << "YES";
  else cout << "NO";
}