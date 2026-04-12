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
  int r,g,b; cin>>r>>g>>b;
  if ((r*100+g*10+b)%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main()
{
  solve();
  return 0;
}
