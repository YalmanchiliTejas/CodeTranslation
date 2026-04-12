#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int x, y;
  cin >> x >> y;
  int s[4];
  s[0] = max(x, y) * 2 * c;
  s[1] = 2 * x * c + max(0, y - x) * b;
  s[2] = 2 * y * c + max(0, x - y) * a;
  s[3] = x * a + y * b;
  int ans = s[0];
  rep(i, 4) ans = min(ans, s[i]);
  cout << ans << endl;
  return 0;
}