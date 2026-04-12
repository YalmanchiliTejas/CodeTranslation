#include <bits/stdc++.h>
using namespace std;

int main() {
  string r, g, b;
  cin >> r >> g >> b;
  int s = atoi((r + g + b).c_str());
  cout << (s % 4 == 0 ? "YES" : "NO") << endl;
}