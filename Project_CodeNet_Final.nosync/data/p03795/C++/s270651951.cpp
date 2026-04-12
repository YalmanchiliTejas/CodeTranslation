#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x;
  cin >> x;

  cout << x*800 - (x/15)*200 << endl;
  return 0;
}
