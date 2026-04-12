#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, g, b;
  cin >> r >> g >> b;
  if (stoi(to_string(r) + to_string(g) + to_string(b)) % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}