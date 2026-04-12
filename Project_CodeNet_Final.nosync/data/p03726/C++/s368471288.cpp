#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR (i, 0, n)
#define _ << " _ " <<
#define TRACE(x) cerr << #x << " = " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
//#define debug
//#define TRACE(x)

using namespace std;

typedef long long llint;

const int MAXN = 100010;

int dp[MAXN][2];
int n;
vector<int> e[MAXN];

int f(int x, int t, int dad) {
  if (dp[x][t] != -1) return dp[x][t];

  int ret = 0;
  
  if (t == 1) {
    ret = 1;
    for (int y : e[x]) {
      if (y == dad) continue;
      ret &= f(y, 0, x);
    }
  } else {
    int cnt0 = 0, tot = 0;
    for (int y : e[x]) {
      if (y == dad) continue;
      ++tot;
      cnt0 += f(y, 0, x);
    }

    ret = 0;
    for (int y : e[x]) {
      if (y == dad) continue;
      int my_cnt = cnt0 - f(y, 0, x);
      if (f(y, 1, x) && my_cnt >= tot - 1)
	ret = 1;
    }
  }

  return dp[x][t] = ret;
}

int main(void) {
  memset(dp, -1, sizeof(dp));
  scanf("%d",&n);
  REP(i, n - 1) {
    int u, v;
    scanf("%d %d",&u,&v);
    --u; --v;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  int mat = f(0,0,-1);
  printf(mat ? "Second\n" : "First\n");
  
  return 0;
}
