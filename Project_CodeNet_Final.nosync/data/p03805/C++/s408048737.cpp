#include <iostream>
#include <queue>
#include <vector>
#define MAX_N 8
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
vector<int> edge[MAX_N + 1];
int ENDH;

int dfs(int v, int h) {
  // cout << "v=" << v << " h=" << h << endl;
  if (h == ENDH) {
    return 1;
  }

  int ret = 0;
  for (auto itr = edge[v].begin(); itr != edge[v].end(); ++itr) {
    int nv = *itr;
    int mask = 0x01 << (nv - 1);
    if ((h & mask) != 0)
      continue;
    int nh = h | mask;
    ret += dfs(nv, nh);
  }
  return ret;
}

int main(void) {
  int N, M;
  cin >> N >> M;
  ENDH = 0;
  rep(i, N) { ENDH = (ENDH << 1) | 0x1; }
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  // dfs
  int ANS = dfs(1, 0x01);
  cout << ANS << endl;
  return 0;
}
