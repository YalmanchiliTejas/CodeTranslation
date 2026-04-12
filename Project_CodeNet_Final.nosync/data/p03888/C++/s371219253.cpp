#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int main() {
  double R1, R2;
  cin >> R1 >> R2;
  cout << fixed << setprecision(10) << (R1 * R2) / (R1 + R2) << endl;
}