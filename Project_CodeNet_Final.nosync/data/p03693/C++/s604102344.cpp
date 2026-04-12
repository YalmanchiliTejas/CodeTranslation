#include <bits/stdc++.h>

using namespace std;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15);
  }
} initializer;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  cout << ((g * 10 + b) % 4 == 0 ? "YES" : "NO") << endl;
}

