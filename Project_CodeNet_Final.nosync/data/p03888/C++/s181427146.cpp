/**
 *    author:  tourist
 *    created: 14.12.2019 10:27:58       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  double r1, r2;
  cin >> r1 >> r2;
  cout << fixed << setprecision(17) << r1 * r2 / (r1 + r2) << '\n';
  return 0;
}
