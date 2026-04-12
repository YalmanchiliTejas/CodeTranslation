#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string r, g, b;
  cin >> r >> g >> b;
  int a = stoi(r + g + b);
  if (a % 4 == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
