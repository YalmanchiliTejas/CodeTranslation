#include <bits/stdc++.h>
using namespace std;

#define name ""
#define ini freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
#define foe(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define long long long 
#define db double 
#define pii pair <int, int>
#define pll pair <long, long>
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1e9+7;
const int MOD = 1e9+7;
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

const int N = 2e5+1;
int n, a[N];
long psum[N], dp[N];

int main()
{
  fastio;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++){
    psum[i] = (i <= 2 ? a[i] : psum[i - 2] + a[i]);  
  }
  for (int i = 2; i <= n; i++) {
    if (i % 2) dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
    else dp[i] = max(dp[i - 2] + a[i], psum[i - 1]);
  }
  cout << dp[n];
  return 0;
}