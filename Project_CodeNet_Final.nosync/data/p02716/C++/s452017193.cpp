// https://atcoder.jp/contests/abc162/tasks/abc162_f

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")
#define DUMP2DLL(a, n, m) REP(_i, n) REP(_j, m) printf("%lld%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 2*1e5;
const int A_I_MAX = 1e9;
const ll INF = 1e15;

int N;
int A[N_MAX];

ll dp0[4][2];
ll dp1[4][2];

void solve() {
  auto cur = dp0;
  auto nxt = dp1;
  fill(cur[0], cur[4], -INF);
  cur[0+1][0] = 0;
  REP(i, N) {
    // DUMP2DLL(cur, 4, 2);
    nxt[-1+1][0] = -INF;
    nxt[-1+1][1] = cur[0+1][0] + A[i];
    nxt[0+1][0] = max(cur[-1+1][0], cur[-1+1][1]);
    nxt[0+1][1] = cur[1+1][0] + A[i];
    nxt[1+1][0] = max(cur[0+1][0], cur[0+1][1]);
    nxt[1+1][1] = cur[2+1][0] + A[i];
    nxt[2+1][0] = max(cur[1+1][0], cur[1+1][1]);
    nxt[2+1][1] = -INF;
    swap(cur, nxt);
  }
  // DUMP2DLL(cur, 4, 2);
  ll ans = max(cur[N % 2 + 1][0], cur[N % 2 + 1][1]);
  printf("%lld\n", ans);
}

void input() {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);
}

int main() {
  input();
  solve();
  return 0;
}
