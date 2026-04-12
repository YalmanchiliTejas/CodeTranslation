#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y; C *= 2;
  cout << (long)min(min(max(X, Y) * C, X * C + max(Y - X, 0) * B), min(Y * C + max(X - Y, 0) * A, X * A + Y * B)) << endl;
}