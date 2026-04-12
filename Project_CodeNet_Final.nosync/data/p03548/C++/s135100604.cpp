#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define RFOR(i, a, b) for(int i=(a); i>=(b); i--)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) RFOR(i, n, 0)
#define dump(x)  cout << #x << " = " << (x) << endl;

typedef long long ll;
typedef pair<int, int> ii;
const ll INF = 1e18;
const ll inf = 1e9;


void solve()
{
  ll X;
  scanf("%lld",&X);
  ll Y;
  scanf("%lld",&Y);
  ll Z;
  scanf("%lld",&Z);
  cout << (X-Z)/(Y+Z) << endl;
}

int main()
{
  solve();
  return 0;
}
