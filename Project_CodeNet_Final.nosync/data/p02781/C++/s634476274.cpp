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

const int N = 102;
long memo[N][2][N];
string s; 
int k, n;

int dp(int i, bool lss, int cur){
  if (i == n){
    return cur == k;
  }
  if (memo[i][lss][cur] != -1) return memo[i][lss][cur];
  int ans = 0;
  for (int d = 0; d < 10; d++){
    if (!(d <= (s[i] - '0') || lss)) continue;
    ans += dp(i + 1, lss | (d < (s[i] - '0')), cur + (d != 0));
  }
  return memo[i][lss][cur] = ans;
}

int main()
{
  fastio;
  cin >> s >> k;
  n = s.size();
  for (int i = 0; i <= n; i++){
    for (int j = 0; j < 2; j++){
      for (int x = 0; x <= n; x++){
        memo[i][j][x] = -1;
      }
    }
  }
  cout << dp(0, 0, 0);
  return 0;
}