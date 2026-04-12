#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define RFOR(i, a, b) for(int i=(a); i>=(b); i--)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) RFOR(i, n, 0)
#define dump(x)  cout << #x << " = " << (x) << endl;

typedef long long ll;
typedef pair<int, int> ii;
const int mod = 1e9+7;
const ll INF = 1e18;
const int inf = 1e9;

void solve()
{
  int n; cin>>n;
  cout << n*800 - n/15*200 << endl;
}

int main()
{
  solve();
  return 0;
}
