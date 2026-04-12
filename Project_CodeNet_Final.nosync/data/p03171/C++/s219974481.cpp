#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <bitset>
using namespace std;

typedef long long ll;
const int MAX_N = 3000 + 2;
ll dp[MAX_N][MAX_N];
ll a[MAX_N];

int main() {

  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];

  memset(dp, 0, sizeof(dp));

  for (int j = 0; j < N; j++) dp[1][j] = a[j];

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j <= N - i; j++) {
      ll front = a[j] + (-1)*dp[i-1][j+1];
      ll back  = a[j+i-1] + (-1)*dp[i-1][j];
      dp[i][j] = max(front, back);
    }
  }

  cout << dp[N][0] << endl;
  return 0;
}
