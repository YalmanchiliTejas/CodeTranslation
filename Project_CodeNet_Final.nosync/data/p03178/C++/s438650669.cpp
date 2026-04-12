// I can't tell you what it really is,
// I can only tell you what it feels like.
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 10000 + 2;
const int mod = 1e9 + 7;

char s[N];
int dp[N][100][2], d, n;


int go(int id, int md, bool f = false) {
  if (id == n) {    
    return !md;
  }
  if (~dp[id][md][f]) return dp[id][md][f];
  long long ans = 0, dig = s[id] - '0';
  for (int i = 0; i < 10; ++i) {
    if (f == false && i > dig) break;
    ans += go(id+1, (md+i)%d, f|(i<dig));
  }
  while (ans >= mod) ans -= mod;
  return dp[id][md][f] = ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s >> d;
  memset(dp, -1, sizeof dp);  
  n = strlen(s);  
  int ans =  go(0,0,0) - 1;
  if (ans < 0) ans += mod;
  cout << ans;  
  return 0;
}
// 1). Try forming/rearranging the equations if any
// 2). If problem asks to count, try counting in reverse(it can be easier sometimes)
