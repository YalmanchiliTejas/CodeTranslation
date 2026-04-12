#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int N, M;
vector<vector<bool>> v;
// n今どこみてるか
int dfs(int n, vector<bool> visited) {
  // 全部訪れてたら1を返す
  for (int i=0; i<N; i++) {
    if (!visited[i]) break;
    if (i==N-1) return 1;
  }

  int res = 0;
  for (int i=0; i<N; i++) {
    if (!v[n][i]) continue;
    if (visited[i]) continue;
    visited[i] = true;
    res += dfs(i, visited);
    visited[i] = false;
  }
  return res;
}

int main(){
  cin >> N >> M;
  v = vector<vector<bool>>(N, vector<bool>(N, false));
  int tmpa, tmpb;
  for (int i=0; i<M; i++) {
    cin >> tmpa >> tmpb;
    tmpa--;
    tmpb--;
    v[tmpa][tmpb] = true;
    v[tmpb][tmpa] = true;
  }

  vector<bool> visited(N, false);
  visited[0] = true;
  int res = dfs(0,visited);
  cout << res << endl;
}
