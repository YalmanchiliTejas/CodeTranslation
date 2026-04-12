#include <iostream>
#include <algorithm>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

int main() {
  int N, M; scanf("%d%d", &N, &M);

  bool edge[N][N];
  rep(i, N) rep(j, N)
    edge[i][j] = false;

  rep(i, M) {
    int a, b; scanf("%d%d", &a, &b);
    --a; --b;
    edge[a][b] = edge[b][a] = true;
  }

  int v[N-1];
  rep(i, N-1) v[i] = i+1;

  int ans = 0;
  do {
    bool flag = true;
    int from = 0, to = v[0];
    rep(i, N-1) {
      if (!edge[from][to])
        flag = false;
      from = v[i], to = v[i+1];
    }
    if (flag)
      ++ans;
  } while(next_permutation(v, v+N-1));
  printf("%d\n", ans);

  return 0;
}
