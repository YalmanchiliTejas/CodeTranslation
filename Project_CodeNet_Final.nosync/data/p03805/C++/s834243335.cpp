#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>

#define INF 10e10
#define REP(i,n) for(int i=0; i<n; i++)
#define REP_R(i,n,m) for(int i=m; i<n; i++)
#define MAX 100

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]) {

  bool all_visited = true;

  for (int i = 0; i < N; i++) {
    if (visited[i] == false) all_visited = false;
  }

  if (all_visited) {
    return 1;
  }

  int ret = 0;

  for (int i = 0; i < N; ++i) {
    if (graph[v][i] == false) continue;
    if (visited[i]) continue;

    visited[i] = true;
    ret += dfs(i, N, visited);
    visited[i] = false;
  }

  return ret;
}

int main() {
  int N,M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int A,B;
    cin >> A >> B;
    graph[A-1][B-1] = graph[B-1][A-1] = true;
  }

  bool visited[nmax];
  for (int i = 0; i < N; i++) {
    visited[i] = false;
  }

  visited[0] = true;
  cout << dfs(0, N, visited) << endl;
  return 0;
}
