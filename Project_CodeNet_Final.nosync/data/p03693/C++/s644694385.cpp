#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << ((a * 100 + b * 10 + c) % 4 ? "NO\n" : "YES\n");
  return 0;
}
