#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x, y, z;
  cin >> x >> y >> z;

  cout << (x - z) / (y + z) << endl;

  return 0;
}