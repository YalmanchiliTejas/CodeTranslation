#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1);
namespace {
  template <typename T> inline void read(T &x) {
    x = 0; T f = 1;char s = getchar();
    for(; !isdigit(s); s = getchar()) if(s == '-') f = -1;
    for(;  isdigit(s); s = getchar()) x = (x << 3) + (x << 1) + (s ^ 48);
    x *= f;
  }
}
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define _for(n,m,i) for (register int i = (n); i < (m); ++i)
#define _rep(n,m,i) for (register int i = (n); i <= (m); ++i)
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define lowbit(x) x & (-x)
#define pii pair<int,int>
#define fi first
#define se second
int k;
char s[110];
int dp[110][4];
int dfs(int step, bool pre, bool limit, int kk) { 
  if(kk > k) return 0;
  if(!s[step]) return kk == k;
  if(!pre && !limit && ~dp[step][kk]) return dp[step][kk];
  int r = limit ? s[step]-'0' : 9;
  int temp = 0;
  for(int i = 0; i <= r; i++) {
    temp += dfs(step+1, pre && i ==0, limit && i == s[step]-'0', kk + (i==0?0:1));
  }
  if(!limit && !pre) dp[step][kk] = temp;
  return temp;
}
 
int main() { 
  scanf("%s %d", s, &k);
  memset(dp, -1, sizeof dp);
  cout << dfs(0, true, true, 0);
} 