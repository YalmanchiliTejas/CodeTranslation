#include <iostream>
#include <cstring>

using namespace std;

typedef long long int ll;

const int N = 4 * 1e3;
ll numbers[N], dp[N][N][2];

ll result(ll currScore, int i, int j, int turn) {
  if (i == j)
    return currScore + turn * numbers[i];

  int dpTurn = (turn < 0 ? 0 : 1);

  if (dp[i][j][dpTurn] != 0)
    return currScore + dp[i][j][dpTurn];

  ll res = (ll)turn * max((ll)turn * result(currScore + turn * numbers[i], i+1, j, -turn), (ll)turn * result(currScore + turn * numbers[j], i, j-1, -turn));
  dp[i][j][dpTurn] = res - currScore;
  return res;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> numbers[i];

  memset(dp, 0, sizeof(dp));

  cout << result(0, 0, n-1, 1) << endl;
}
