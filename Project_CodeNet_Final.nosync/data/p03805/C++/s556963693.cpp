#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << (x) << endl
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> V;

int n, m;
vector<vector<int>> v(8);
int cnt;

void dfs(int x, vector<bool> mp) {
  if (mp[x-1]) return;
  mp[x-1] = true;
  int i = 0;
  while (i < n && mp[i]) i++;
  if (i == n) {
    cnt++;
    return;
  }
  for (int j = 0; j < (int)v[x-1].size(); j++) {
    dfs(v[x-1][j], mp);
  }
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    pi tmp;
    cin >> tmp.first >> tmp.second;
    v[tmp.first-1].push_back(tmp.second);
    v[tmp.second-1].push_back(tmp.first);
  }
  vector<bool> x(n, false);
  dfs(1, x);
  dump(cnt);
  return 0;
}
