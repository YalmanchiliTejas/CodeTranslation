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

vector<ll> a,p;

ll f(ll n, ll x) {
  if (n==0) return x<=0 ? 0 : 1;
  else if (x <= 1+a[n-1]) return f(n-1, x-1);
  else return p[n-1] + 1 + f(n-1, x-2-a[n-1]);
}

void solve()
{
  a.push_back(1);
  p.push_back(1);
  ll n,x; cin>>n>>x;
  for (int i=0; i<n; i++) {
    a.push_back(a[i]*2 + 3);
    p.push_back(p[i]*2 + 1);
  }
  cout << f(n,x) << endl;
}

int main()
{
  solve();
  return 0;
}
