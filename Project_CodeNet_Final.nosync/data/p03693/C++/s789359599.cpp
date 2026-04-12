#include <bits/stdc++.h>

using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;

  int gb = g * 10 + b;

  string answer = gb % 4 == 0 ? "YES" : "NO";

  cout << answer << endl;
}