// review
#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 10;

int n, m;
bool graph[MAXN][MAXN];
bool visited[MAXN];
ll cnt = 0;

void dfs(int s) {
  bool done = true;
  for (int i=0;i<n;i++) {
    done &= visited[i];
  }
  if (done) {
    cnt++;
    return;
  }
  for (int i=0;i<n;i++) {
    if (graph[s][i] && !visited[i]) {
      visited[i] = true;
      dfs(i);
      visited[i] = false;
    }
  }
}

void solve() {
  visited[0] = true;
  dfs(0);
  cout << cnt << endl;
}


int main() {
  cin >> n >> m;
  int a, b;
  for (int i=0;i<m;i++) {
    cin >> a >> b;
    graph[--a][--b] = true;
    graph[b][a] = true;
  }
  solve();
}
