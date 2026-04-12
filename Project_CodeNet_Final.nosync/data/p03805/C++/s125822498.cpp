#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int v[10][10];
int n, m, ans;

void dfs(int from, int visited) {
  visited |= (1 << from);
  for (int i = 0; i < n; i++)
    if (v[from][i] == 1 && !((1 << i) & visited)) dfs(i, visited);
  if (visited == (1 << n) - 1) ans++;
}

int main() {
  cin >> n >> m;
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    v[a][b] = 1;
    v[b][a] = 1;
  }
  dfs(0, 0);
  cout << ans << endl;
}
