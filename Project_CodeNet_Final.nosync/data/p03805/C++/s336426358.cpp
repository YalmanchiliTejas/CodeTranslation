#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 8;

vector<int> p[MAX_N];
bool visited[MAX_N];
int N, M, ans = 0;

void dfs(int x) {
  if (visited[x]) return;

  visited[x] = true;
  for (vector<int>::iterator it=p[x].begin(); it!=p[x].end(); ++it) {
    dfs(*it);
  }

  bool flag = true;
  for (int i=0; i<N; i++) {
    if (!visited[i]) flag = false;
  }
  if (flag) ans++;
  visited[x] = false;
}

int main() {
  int a, b;
  cin >> N >> M;
  for (int i=0; i<N; i++) {
    visited[i] = false;
  }
  for (int i=0; i<M; i++) {
    cin >> a >> b; a--; b--;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  dfs(0);
  cout << ans << endl;
  return 0;
}
