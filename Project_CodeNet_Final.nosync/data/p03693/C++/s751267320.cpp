#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main() {
  string r, g, b;
  cin >> r >> g >> b;
  if (stoi(r + g + b) % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}