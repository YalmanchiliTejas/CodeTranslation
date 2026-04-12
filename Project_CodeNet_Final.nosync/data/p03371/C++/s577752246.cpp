#include <bits/stdc++.h>
using namespace std;

#define SORT(x) sort((x).begin(),(x).end())
#define RSORT(x) sort((x).begin(),(x).end(),greater<int>())
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) " (L" << __LINE__ << ") " << __FILE__ << endl;

typedef long long ll;
const int mod = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;

void solve()
{
  int a,b,c;cin>>a>>b>>c;
  int x,y;cin>>x>>y;
  c*=2;

  ll ans=INF;
  for (int i=0; i<=max(x,y); i++) {
    ll m=0;
    m = c*i;
    m += a * max(0, x-i);
    m += b * max(0, y-i);
    ans = min(ans, m);
  }

  cout << ans << endl;
}

int main()
{
  solve();
  return 0;
}
