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
const int MOD = 998244353;
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

long dp[3001];

int main()
{
  fastio;
  int n, s; long res = 0;
  cin >> n >> s;
  for (int i = 1; i <= n; i++){
    int x; cin >> x;
    if (x > s) continue;
    if (x == s){
      (res += 1ll * i * (n - i + 1)) %= MOD;
    }
    else{
      (res += dp[s - x] * (n - i + 1)) %= MOD;
      for (int j = s; j > x; j--) (dp[j] += dp[j - x]) %= MOD;
      (dp[x] += i) %= MOD;
    }
  }
  cout << res;
  return 0;
}