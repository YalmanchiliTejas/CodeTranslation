#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1LL<<60;
const int mod = 1e9 + 7;
const double eps = 1e-9;

/*{
}*/

signed main()
{
  int n;
  cin >> n;
  
  vi v(n);
  rep(i, n) cin >> v[i];
  
  int ans = 0;
  for(int i = 0; ; i = (i+1)%n){
    int t = v[i]/n; 
    v[i] -= t*n;
    ans += t;

    int ma = -1;
    rep(j, n){
      if(i != j) v[j] += t;
      ma = max(ma, v[j]);
    }
    if(ma < n) break;
  }

  cout << ans << endl;

  return 0;
}
