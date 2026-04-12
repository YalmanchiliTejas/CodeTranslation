#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, maxh; cin >> n >> maxh;
  int h, c = 1;
  for (int i = 1; i < n; i++) {
    cin >> h;
    if (h >= maxh) c++, maxh = h;
  }
  cout << c << endl;
}