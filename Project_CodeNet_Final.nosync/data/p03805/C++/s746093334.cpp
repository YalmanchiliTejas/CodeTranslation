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

int main() {
  fscanf(stdin, "%d%d ", &n, &m);
  REP(i,m) {
    int a, b;
    fscanf(stdin, "%d%d ", &a, &b);
    a--; b--;
    g[a][b] = g[b][a] = 1;
  }
  int res = 0;
  vector<int> p(n);
  REP(i,n) p[i] = i;
  do {
    if (p[0]) continue;
    int ok = 1;
    REP(i,n-1) if (!g[p[i]][p[i+1]]) ok = 0;
    if (ok) res++;
  } while (next_permutation(all(p)));
  fprintf(stdout, "%d\n", res);
  return 0;
}
