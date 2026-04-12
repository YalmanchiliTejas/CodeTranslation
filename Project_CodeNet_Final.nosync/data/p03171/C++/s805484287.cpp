#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

using ll = long long;

ll memo[3001][3001];
ll sum[3001];
int N;
int a[3000];

void init()
{
  cin >> N;
  rep(i, N) {
    cin >> a[i];
    sum[i+1] = sum[i] + a[i];
    rep(j, N+1) {
      if (i == j) continue;
      memo[i][j] = -1;
      memo[j][i] = -1;
    }
  }
}

ll dfs(int s, int t)
{
  ll& res = memo[s][t];
  if (res != -1) return res;
  ll x = a[s] + (sum[t] - sum[s+1]) - dfs(s+1, t);
  ll y = a[t-1] + (sum[t-1] - sum[s]) - dfs(s, t-1);
  return res = max(x, y);
}

int main()
{
  init();
  ll x = dfs(0, N);
  ll y = sum[N] - x;
  cout << x - y << endl;
}