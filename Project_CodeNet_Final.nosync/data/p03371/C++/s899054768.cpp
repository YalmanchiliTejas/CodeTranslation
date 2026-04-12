#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  c = 2 * c;
  int ans = 1e9;
  for (int i = 0; i <= max(x, y); ++i) {
    int tmp = c * i;
    tmp += a * max(0, x - i);
    tmp += b * max(0, y - i);
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}