#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i = (a); i <= (b); ++ i)
#define rrp(i,a,b) for (int i = (a); i >= (b); -- i)
#define gc() getchar()
#define fir first
#define sec second
typedef pair<int,int> pii;
typedef long double db;
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

const int N = 110;
int dp[N][N], hei[N], n;
vector<int> tmp;
int main() {
  read(n);
  rep (i, 1, n)
    read(hei[i]), tmp.push_back(hei[i]);
  hei[0] = 1, tmp.push_back(1);
  sort(tmp.begin(), tmp.end());
  tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
  rep (i, 0, n)
    hei[i] = lower_bound(tmp.begin(), tmp.end(), hei[i]) - tmp.begin();
  dp[0][n] = 1;
  rep (i, 1, n) {
    rep (j, 0, min(hei[i-1], hei[i]))
      Add(dp[i][j], 1ll * dp[i-1][j] * power(2, max(0, tmp[hei[i]] - tmp[hei[i-1]])) % MOD);
    int sum = 0;
    rep (j, min(hei[i-1], hei[i])+1, n)
      Add(sum, dp[i-1][j]);
    sum = (sum * 2) % MOD;
    rep (j, min(hei[i-1], hei[i])+1, hei[i]) {
      int v = power(2, tmp[j] - tmp[j-1]) - 1;
      v = 1ll * v * power(2, tmp[hei[i]] - tmp[j]) % MOD;
      Add(dp[i][j], 1ll * v * sum % MOD);
    }
    Add(dp[i][n], sum);
  }
  int ans = 0;
  rep (i, 0, n) Add(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}
