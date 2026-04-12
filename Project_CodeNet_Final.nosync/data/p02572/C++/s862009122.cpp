/**
 *  winners never quit
**/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pp pop_back
#define mp make_pair
#define IO cin.tie(0),cout.tie(0)
#define ISWS ios::sync_with_stdio(0)
typedef long long Long;
void FastIO(){ISWS;IO;}

const int N = 1e5;

Long m = 1e9 + 7;

int main()
{
  FastIO();
  int tc, ca = 0;
  Long n;
  cin >> n;
  vector <Long> a(n);
  Long ps = 0;
  Long ans = 0;
  for (int i = 0;i < n;i++){
    cin >> a[i];
    ans += a[i] * ps;
    ps += a[i];
    ans %= m;
    ps %= m;
  }

  cout << ans << '\n';
  return 0;
}
