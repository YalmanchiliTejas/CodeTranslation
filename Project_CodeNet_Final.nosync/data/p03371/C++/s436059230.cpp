#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int sum = INT_MAX;
  int cn_max = max(x, y) * 2;
  for (int cn = 0; cn <= cn_max; cn++) {
    int an = max(x - cn / 2, 0);
    int bn = max(y - cn / 2, 0);

    // printf("an=%d, bn=%d, cn=%d\n", an, bn, cn);
    sum = min(an*a + bn*b + cn*c, sum);
  }

  cout << sum << endl;

  return 0;
}
