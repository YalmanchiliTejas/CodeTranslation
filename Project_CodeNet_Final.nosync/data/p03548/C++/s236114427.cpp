#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x, y, z;
  cin >> x >> y >> z;

  int total = z;
  int count = 0;
  for (;x >= total + z + y;) {
    total += z + y;
    count++;
  }

  cout << count << endl;

  return 0;
}