#include <bits/stdc++.h>
using namespace std;

int main() {
  string r, g, b, n;
  cin >> r >> g >> b;
  cout << (atoi((r + g + b).c_str()) % 4 == 0 ? "YES" : "NO") << endl;
}