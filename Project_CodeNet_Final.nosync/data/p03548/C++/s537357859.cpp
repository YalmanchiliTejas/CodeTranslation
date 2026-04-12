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
  int x,y,z;
  cin >> x >> y >> z;
  cout << 1+(x-y-2*z)/(y+z) << endl;
  return 0;
}
