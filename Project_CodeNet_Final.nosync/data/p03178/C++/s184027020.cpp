#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define ll long long
#define fastIO cout << fixed << setprecision(12), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-9, PI = acos(-1);
const int N = 1e4 + 9, M = 1e2 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

ll add(ll a, ll b) {
  a += b;
  if(a >= MOD)
    a -= MOD;
  if(a < 0)
    a += MOD;
  return a;
}

ll mem[N][M][3], n;
string mx;

ll solve(int len, int sum, int can) {
  if(len == (int)mx.size())
    return (can > 0) && (!sum);
  ll& ret = mem[len][sum][can];
  if(~ret)
    return ret;
  ret = 0;
  for (int i = 0; i < 10; ++i) {
    int nwVal;
    if(can != 2)
      nwVal = can;
    else {
      if(i + '0' < mx[len])
        nwVal = 1;
      else if(i + '0' == mx[len])
        nwVal = 2;
      else
        nwVal = 0;
    }
    ret = add(ret, solve(len + 1, ((sum + i ) % n), nwVal ));
  }
  return ret;
}

int main() {
  fastIO;
#ifdef LOCAL
  freopen("input.in", "rt", stdin);
#endif
  cin >> mx >> n;
  memset(mem, -1, sizeof mem);
  ll ans = add(solve(0, 0, 2), -1);
  cout << ans;
  return 0;
}
