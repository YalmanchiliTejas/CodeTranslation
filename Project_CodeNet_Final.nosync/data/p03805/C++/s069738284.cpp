#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n, m, a[100], b[100], path[10][10], cnt = 0;

void solve(int i) {
  if(i == n - 1) {
    ++cnt;
    return;
  }
  if(path[v[i]][v[i + 1]] != -1) { solve(i + 1); }
}

int main(void) {
  for(int i = 0; i < 10; ++i)
    for(int j = 0; j < 10; ++j) path[i][j] = -1;
  cin >> n >> m;
  for(int i = 0; i < n; ++i) v.push_back(i + 1);
  for(int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i];
    path[a[i]][b[i]] = 1;
    path[b[i]][a[i]] = 1;
  }
  do {
    if(v[0] != 1) break;
    solve(0);
  } while(next_permutation(v.begin(), v.end()));
  cout << cnt << endl;
}
