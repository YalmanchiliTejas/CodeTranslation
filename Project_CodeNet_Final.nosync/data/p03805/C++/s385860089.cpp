#include <cstdio>
#include <vector>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int N_MAX = 8;
const int M_MAX = 30;

int N, M;
int a[M_MAX];
int b[M_MAX];
int S;
vector<int> G[N_MAX];

int dfs(int v, int s) {
  if (s == S) return 1;
  int ret = 0;
  REP(i, G[v].size()) {
    int u = G[v][i];
    if (s >> u & 1) continue;
    ret += dfs(u, s | 1 << u);
  }
  return ret;
}

void solve() {
  REP(i, M) {
    G[a[i] - 1].push_back(b[i] - 1);
    G[b[i] - 1].push_back(a[i] - 1);
  }
  S = (1 << N) - 1;
  printf("%d\n", dfs(0, 1));
}

void input() {
  scanf("%d%d", &N, &M);
  REP(i, M) scanf("%d%d", a + i, b + i);
}

int main() {
  input();
  solve();
  return 0;
}
