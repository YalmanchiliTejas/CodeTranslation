#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
int dp [MAX_N][2];
// dp[u][i] -- is there a perf. matching in sub of u
// with u matched up if i is 1

void dfs (int u, int p) {
  int c00 = 0;
  int c01 = 0;
  int c10 = 0;
  int c11 = 0;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      dfs(nxt, u);

      if (dp[nxt][0]) {
        if (dp[nxt][1]) {
          c11++;
        } else {
          c10++;
        }
      } else {
        if (dp[nxt][1]) {
          c01++;
        } else {
          c00++;
        }
      }
    }
  }

  if (c00 == 0) {
    // determine dp[u][1]
    dp[u][1] = (c01 == 0);

    // determine dp[u][0]
    dp[u][0] = (c01 <= 1) && (c01 + c11 > 0);
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);

  cout << (dp[1][0] ? "Second" : "First") << '\n';
}
