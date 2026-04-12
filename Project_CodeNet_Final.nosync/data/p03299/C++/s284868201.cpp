#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long li;

const int Mod = 1e9 + 7;

inline int Add(int x, int y) {
  x += y;
  if (x >= Mod) x -= Mod;
  else if (x < 0) x += Mod;
  return x;
}
inline int Mul(int x, int y) {
  return 1LL * x * y % Mod;
}
int Pow(int a, int b) {
  int res = (a == 0) ? 0 : 1;
  while (b) {
    if (b & 1) res = Mul(res, a);
    a = Mul(a, a);
    b >>= 1;
  }
  return res;
}

const int N = 110;
int n, h[N];
int f[N][N][2][2][2], g[2][2][2];

int Getmin(int l, int r) {
  int res = Mod;
  for (int i = l; i <= r; ++i)
    res = min(res, h[i]);
  return res;
}
void Calc(int l, int r, int delta_h) {
  memset(g, 0, sizeof g);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) {
      if (delta_h) {
	g[i][j][0] = Add(g[i][j][0], Mul(f[l][r][i][j][0], Pow(2, delta_h - 1)));
	g[j][i][0] = Add(g[j][i][0], Mul(f[l][r][i][j][0], Pow(2, delta_h - 1)));
      } else {
	g[i][j][0] = Add(g[i][j][0], f[l][r][i][j][0]);
      }
      if (delta_h & 1) {
	g[i ^ 1][j ^ 1][1] = Add(g[i ^ 1][j ^ 1][1], f[l][r][i][j][1]);
      } else {
	g[i][j][1] = Add(g[i][j][1], f[l][r][i][j][1]);
      }
    }
  memcpy(f[l][r], g, sizeof g);
}
void Merge(int l, int r, int nowl, int nowr) {
  memset(g, 0, sizeof g);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k)
	for (int xi = 0; xi < 2; ++xi)
	  for (int xj = 0; xj < 2; ++xj)
	    for (int xk = 0; xk < 2; ++xk) {
	      int p = i, q = xj;
	      int s = k || xk || (j == xi);
	      int now = Mul(f[l][r][i][j][k], f[nowl][nowr][xi][xj][xk]);
	      g[p][q][s] = Add(g[p][q][s], now);
	    }
  memcpy(f[l][r], g, sizeof g);
}
void Solve(int l, int r) {
  if (l == r) {
    f[l][r][0][0][0] = f[l][r][1][1][0] = 1;
    return;
  }
  vector<pair<int, int> >now;
  int hmin = Getmin(l, r);
  int pre = l;
  for (int i = l; i <= r; ++i)
    if (h[i] == hmin) {
      if (pre < i) now.pb(mp(pre, i - 1));
      now.pb(mp(i, i));
      pre = i + 1;
    }
  if (pre <= r) now.pb(mp(pre, r));
  for (int i = 0; i < (int)now.size(); ++i) {
    int nowl = now[i].first, nowr = now[i].second;
    Solve(nowl, nowr);
    Calc(nowl, nowr, Getmin(nowl, nowr) - hmin);
    if (i) Merge(l, r, nowl, nowr);
    else memcpy(f[l][r], f[nowl][nowr], sizeof g);
  }
}

int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &h[i]);
  Solve(1, n);
  Calc(1, n, Getmin(1, n) - 1);
  int ans = 0;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k)
	ans = Add(ans, f[1][n][i][j][k]);
  printf("%d\n", ans);

  return 0;
}
