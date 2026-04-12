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

const int N = 1e4+1;
string s;
int n, D, memo[N][2][100];

int dp(int i, bool lss, int mod){
  if (i == n){
    return (mod == 0);
  }
  if (memo[i][lss][mod] != -1) return memo[i][lss][mod];
  int ans = 0;  
  for (int d = 0; d < 10; d++){
    if (!(d <= s[i] - '0' || lss)) continue;
    ans += dp(i + 1, (lss | d < s[i] - '0'), (mod + d) % D);  
    ans %= MOD;
  }
  return memo[i][lss][mod] = ans;
}

int main()
{
  fastio;
  cin >> s >> D;
  n = s.size();
  for (int i = 0; i <= n; i++){
    for (int j = 0; j < D; j++){
      memo[i][0][j] = memo[i][1][j] = -1;
    }
  }
  cout << (dp(0, 0, 0) - 1 + MOD) % MOD;;
  return 0;
}