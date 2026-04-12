#include <bits/stdc++.h>

using namespace std;

#define FOR(i,s,e) for(int i=(s);(i)<(int)(e);(i)++)
#define REP(i,e) FOR(i,0,e)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp make_pair
#define mt make_tuple
#define t0(t) get<0>((t))
#define t1(t) get<1>((t))
#define t2(t) get<2>((t))

typedef long long ll;
const int N = 8;
int n, m;
int g[N][N];

int dfs(int s, int n, int p[N]) {
  int done = 1;
  REP(i,n) done &= p[i];
  if (done) return 1;
  int res = 0;
  REP(i,n) {
    if (!g[s][i]) continue;
    if (p[i]) continue;
    p[i] = 1;
    res += dfs(i,n,p);
    p[i] = 0;
  }
  return res;
}

int main() {
  fscanf(stdin, "%d%d ", &n, &m);
  REP(i,m) {
    int a, b;
    fscanf(stdin, "%d%d ", &a, &b);
    a--; b--;
    g[a][b] = g[b][a] = 1;
  }
  int p[N];
  memset(p, 0, sizeof(p));
  p[0] = 1;
  fprintf(stdout, "%d\n", dfs(0,n,p));
  return 0;
}
