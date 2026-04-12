#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 9999999999;
#define D(x) cout << x << endl;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

int n, m;
int g[10][10];

int ans;
bool used[10];
void dfs(int v, int cnt) {
  if (cnt == n) {
    ans++;
    return;
  }
  used[v] = 1;
  for (int i = 0; i < n; i++) {
    if (!used[i] && g[v][i]) {
      dfs(i, cnt + 1);
    }
  }
  used[v] = 0;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a][b] = g[b][a] = 1;
  }

  dfs(0, 1);
  D(ans);

  return 0;
}
