#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> connect;
int dp[8][256];

int Ways(int pos, int bit) {
  if (dp[pos][bit])
    return dp[pos][bit];
  int visited = bit ^ (1 << pos);
  int sum = 0;
  for (int a : connect[pos]) {
    if ((1 << a) & bit)
      sum += Ways(a, visited);
  }
  return dp[pos][bit] = sum;
}

int main() {
  int n, m;
  cin >> n >> m;
  connect.resize(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    connect[a - 1].push_back(b - 1);
    connect[b - 1].push_back(a - 1);
  }
  dp[0][1] = 1;

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += Ways(i, (1 << n) - 1);
  }
  cout << sum << "\n";

  return 0;
}
