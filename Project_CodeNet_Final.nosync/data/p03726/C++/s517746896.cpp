#include <bits/stdc++.h>

using namespace std;

int const N = 1234567;

vector<int> edges[N];

int dfs(int v, int pv) {
  int c1 = 0;
  for (int to : edges[v]) {
    if (to == pv) continue;
    int got = dfs(to, v);
    if (got == 2) {
      return 2;
    }
    if (got == 1) c1++;
  }
  if (c1 == 0) {
    return 1;
  }
  if (c1 > 1) {
    return 2;
  }
  return 0;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    edges[v].push_back(u);
    edges[u].push_back(v);
  }
  if (dfs(0, -1) >= 1) {
    puts("First");
  } else {
    puts("Second");
  }
}
