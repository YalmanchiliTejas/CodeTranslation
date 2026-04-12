#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

long long dp[3100][3100];
bool used[3100][3100];
long long a[3100];
int N;

long long dfs(int i, int j)
{
  if (j - i == 0) return 0;
  long long &res = dp[i][j];
  if (used[i][j]) return res;
  used[i][j] = true;

  int len = j - i;
  if ((N - len) % 2 == 0) res = max(dfs(i + 1, j) + a[i], dfs(i, j - 1) + a[j - 1]);
  else res = min(dfs(i + 1, j) - a[i], dfs(i, j - 1) - a[j - 1]);
  return res;
}

int main()
{
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  cout << dfs(0, N) << endl;

  return 0;
}