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
  double r1, r2;
  cin >> r1 >> r2;
  cout << 1 / (1 / r1 + 1 / r2) << endl;
}
