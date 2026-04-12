#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
const double PI = 3.14159265358979323846;
template <class T, class U>
void chmin(T& t, const U& u) {
  if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
  if (t < u) t = u;
}

int main(void) {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int minp;
  minp = (2 * c <= a + b ? 2 * c : a + b);
  int res = 0;
  int cnt = 0;
  while (cnt < x && cnt < y) {
    res += minp;
    cnt++;
  }
  if (a > minp) a = minp;
  if (b > minp) b = minp;
  res += (x - cnt) * a + (y - cnt) * b;
  cout << res << endl;
  return 0;
}