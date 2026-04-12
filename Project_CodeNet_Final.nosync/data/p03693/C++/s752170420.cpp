#include <bits/stdc++.h>
#define sz(arr) (int)arr.size()

using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;

  int sum = stoi(to_string(r) + to_string(g) + to_string(b));

  puts(sum % 4 == 0 ? "YES" : "NO");

  return 0;
}