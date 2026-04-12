#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector<int> g[N];
int dp[N];
bool flag = false;

void dfs(int u, int fa) {
  dp[u] = 0;
  int sum = 0;
  for (auto v : g[u]) {
    if (v != fa) {
      dfs(v, u);
      if (dp[v] == 0) {
        sum++;
      }
    }
  }
  if (sum == 0) {
    dp[u] = 0;
  } else if (sum == 1) {
    dp[u] = 1;
  } else {
    flag = true;
  }
}

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  flag |= (dp[1] == 0);
  puts(flag ? "First" : "Second");
  return 0;
}
