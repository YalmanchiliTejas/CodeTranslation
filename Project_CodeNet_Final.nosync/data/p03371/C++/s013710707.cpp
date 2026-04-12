#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define MAX_C 1000000001

int main() {
  int a, b, c, x ,y;
  cin >> a >> b >> c >> x >> y;
  ll pay = 0;

  int buy = min(x, y); 
  x -= buy;
  y -= buy;
  pay += buy * min(a + b, 2 * c);

  if (x > 0) pay += min(a, 2 * c) * x;
  if (y > 0) pay += min(b, 2 * c) * y;

  cout << pay << endl;
}
