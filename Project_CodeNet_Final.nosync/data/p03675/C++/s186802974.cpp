#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back 
#define mp make_pair
#define fr first
#define sc second
#define Rep(i, n) for( int i = 0; i < (n); i++ )
#define Rrep(i, a, n) for( int i = (a); i < (n); i++ )
#define All(v) v.begin(), v.end()

typedef pair<int, int> Pii; 
typedef pair<int, Pii> Pip;
const int INF = 1107110711071107;
int a[1000000];
int ans[1000000];
signed main()
{
  int n;
 
  int cnt1 = 0, cnt2 = 0;

  cin >> n;
  Rep(i, n) cin >> a[i];

  for ( int i = n - 1; i >= 0; i -= 2 ) {
    ans[cnt1] = a[i];
    cnt1++;
    if ( cnt1 + cnt2 >= n ) break;
    ans[n - 1 - cnt2] = a[i - 1];
    cnt2++;
  }

  Rep(i, n) cout << ans[i] << " ";
  cout << endl;
}
