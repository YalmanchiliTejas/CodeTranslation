#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;

int N;
vector<vector<int>> to;

int dfs(int n, vector<bool> visited) {
  visited[n] = true;
  bool fin=true;
  for(int i=0; i<visited.size(); i++) {
    if(!visited[i]) {
      fin = false;
      break;
    }
  }
  if(fin)
    return 1;
  int ret=0;
  for(int i=0; i<to[n].size(); i++) {
    if(!visited[to[n][i]])
      ret += dfs(to[n][i], visited);
  }
  return ret;
}

int main() {
  int M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  rep(i, M) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  to = vector<vector<int>>(N);
  rep(i, M) {
    to[a[i]].push_back(b[i]);
    to[b[i]].push_back(a[i]);
  }
  vector<bool> v(N, false);
  cout << dfs(0, v) << endl;
  return 0;
}