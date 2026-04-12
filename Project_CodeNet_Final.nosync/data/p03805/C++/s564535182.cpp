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

const int nmax = 8;
bool graph[nmax][nmax];
int N,M;

int dfs(int v, int i, bool visited[nmax]);

int main() {
  cin >> N >> M;
  REP(i,M) {
    int a,b;
    cin >> a >> b;
    graph[a-1][b-1] = graph[b-1][a-1] = true;
  }

  int res = 0;
  bool visited[nmax];

  REP(i,nmax) visited[i] = false;

  visited[0] = true;

  res = dfs(0, N, visited);
  cout << res << endl;
}

int dfs(int v, int N, bool visited[nmax]) {
  bool all_visited = true;

  REP(i,N) {
    if (!visited[i]) all_visited = false;
  }

  if (all_visited) return 1;

  int res = 0;

  for (int i = 0; i < N; i++) {
    if (!graph[v][i]) continue;
    if (visited[i]) continue;

    visited[i] = true;
    res += dfs(i, N, visited);
    visited[i] = false;
  }

  return res;
}
