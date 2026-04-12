#include <vector>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define REP(i,n) for(int i=0;i<n;i++)
#define SORT(c) sort((c).begin(),(c).end())
#define ALL(a) (a).begin(),(a).end()

const int nmax=8;
bool graph[nmax][nmax];

int dfs(int v, int n, bool visited[nmax]) {
  bool all_visited = true;

  REP(i, n) {
    if(visited[i] == false) {
      all_visited = false;
    }
  }

  if(all_visited) {
    return 1;
  }

  int ret = 0;

  REP(i, n) {
    if(graph[v][i] == false) continue;
    if(visited[i]) continue;

    visited[i] = true;
    ret += dfs(i, n, visited);
    visited[i] = false;
  }

  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m;
  cin >> n >> m;
  REP(i, m) {
    int a,b;
    cin >> a >> b;
    graph[a-1][b-1] = graph[b-1][a-1] = true;
  }

  bool visited[nmax];
  REP(i, n) {
    visited[i] = false;
  }

  visited[0] = true;
  cout << dfs(0, n, visited) << endl;
  return 0;
}
