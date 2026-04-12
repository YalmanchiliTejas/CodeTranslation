#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i = (a); i <= (b); ++ i)
#define rrp(i,a,b) for (int i = (a); i >= (b); -- i)
#define gc() getchar()
#define fir first
#define sec second
typedef pair<int,int> pii;
typedef double db;
typedef long long ll;
template <typename tp>
inline void read(tp& x) {
  x = 0; char tmp; bool key = 0;
  for (tmp = gc(); !isdigit(tmp); tmp = gc())
    key = (tmp == '-');
  for (; isdigit(tmp); tmp = gc()) 
    x = (x << 3) + (x << 1) + (tmp ^ '0');
  if (key) x = -x;
}
template <typename tp>
inline void ckmn(tp& x,tp y) {
  x = x < y ? x : y;
}
template <typename tp>
inline void ckmx(tp& x,tp y) {
  x = x < y ? y : x;
}

const int MOD = (int)(1e9 + 7);
inline void Add(int& x,int y) {
  x = x + y >= MOD ? x + y - MOD : x + y;
}
inline void Sub(int& x,int y) {
  x = x - y < 0 ? x - y + MOD : x - y;
}
int power(int a,int b) {
  int ret = 1;
  while (b) {
    if (b&1) ret = 1ll * ret * a % MOD;
    a = 1ll * a * a % MOD;
    b >>= 1;
  }
  return ret;
}

const int N = 200010;
int n, m, arr[N], acnt;
char str[N];
int dp[N];
void doit(int lim) {
  if (n%2) {
    puts("0");
    return;
  }
  lim = (lim + 1) / 2;
  rep (i, 1, n/2) {
    Add(dp[i], dp[i-1]);
    if (i-lim-1 >= 1)
      Sub(dp[i], dp[i-lim-1]);
    if (i <= lim) Add(dp[i], 2 * i);
    Add(dp[i], dp[i-1]);
  }
  int ans = dp[n/2];
  Sub(ans, dp[n/2-1]);
  printf("%d\n", ans);
}
int main() {
  read(n), read(m);
  scanf("%s", str+1);
  if (str[1] == 'R') {
    rep (i, 1, m) {
      if (str[i] == 'R') str[i] = 'B';
      else str[i] = 'R';
    }
  }
  int key = 1;
  rep (i, 2, m) if (str[i] == 'R') key = 0;
  if (key) {
    dp[0] = 1, dp[1] = 2;
    rep (i, 2, n) dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    int ans = dp[n];
    if (n >= 3) Sub(ans, dp[max(0, n - 4)]);
    printf("%d\n", ans);
    return 0;
  }
  for (int i = 1, j = 0; i <= m; ++ i) {
    if (str[i] == 'B') {
      ++ j;
      if (str[i+1] == 'R' && i <= m)
	arr[++ acnt] = j;
    }
    else j = 0;
  }
  int lim = n;
  rep (i, 2, acnt) {
    if (arr[i] % 2 != 0)
      lim = min(lim, arr[i]); 
  }
  lim = min(lim, arr[1] + 1);
  doit(lim);
  return 0;
}
