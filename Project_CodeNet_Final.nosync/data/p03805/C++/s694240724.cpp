#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
struct edge { int u, v; ll w; };
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
bool adjacent[8][8];

int DFS (int v, int N, bool visited[8]) {

  // すべてのノードに訪れているか判定
  bool all = true;
  for (int i = 0; i < N; i++) {
    if (visited[i] == false) all = false;
  }
  if (all) return 1;

  int ret = 0;
  for (int i = 0; i < N; i++) {
    // vとiが隣接していない
    if (adjacent[v][i] == false) continue;
    // 次の頂点が訪問済み
    if (visited[i]) continue;
    visited[i] = true;
    ret += DFS(i, N, visited);
    visited[i] = false;
  }
  return ret;
}

int main() {
  int N, M;

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    adjacent[a - 1][b - 1] = adjacent[b - 1][a - 1] = true;
  }
  bool visited[8];
  for (int i = 0; i < N; i++)
    visited[i] = false;

  visited[0] = true;
  cout << DFS(0, N, visited) << endl;

}
