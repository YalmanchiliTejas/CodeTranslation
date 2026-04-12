#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, N;
  cin >> N;
  x = 800 * N;
  y = 200 * (N / 15);
  cout << x - y;
}