#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define ALL(c) (c).begin(), (c).end()

int g[10][10];
int n, m;

int dfs(int S, int pre) {
  if (S == (1 << n) - 1) return 1;
  int ans = 0;
  REP(i,n) {
    if (!(S >> i & 1) && g[pre][i]) {
      ans += dfs(S|1<<i,i);
    }
  }
  return ans;
}

int main() {
  while (cin >> n >> m) {
    memset(g,0,sizeof(g));

    REP(i,m) {
      int a, b;
      cin >> a >> b;
      a--;b--;
      g[a][b] = g[b][a] = 1;
    }

    cout << dfs(1<<0, 0) << endl;
  }
}
