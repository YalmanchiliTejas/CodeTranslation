#include <iostream>
#include <vector>
using namespace std;

int N, M, cnt;
vector<int> es[10];
bool used[10];

void dfs(int now)
{
  used[now] = true;
  for (int i = 1; i <= N; i++) {
    if (!used[i]) break;
    if (i == N) {
      cnt++;
      used[now] = false;
      return;
    }
  }

  for (int i = 0; i < es[now].size(); i++) {
    if (used[es[now][i]]) continue;
    dfs(es[now][i]);
  }
  used[now] = false;
}

int main()
{
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int v1, v2; cin >> v1 >> v2;
    es[v1].push_back(v2);
    es[v2].push_back(v1);
  }

  dfs(1);
  cout << cnt << endl;
}

