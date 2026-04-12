#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)


int a, b, c, x, y;

long long solve()
{
  long long ans = LLONG_MAX;
  for (long long i = 0; i <= 1000000; ++i)
    ans = min(ans, max(x - i, 0LL) * a + max(y - i, 0LL) * b + 2 * i * c);
  return ans;
}

int main()
{
  cin >> a >> b >> c >> x >> y;
  cout << solve() << endl;
}
