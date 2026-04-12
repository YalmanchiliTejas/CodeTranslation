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
ll a[MAX_N];
ll dp[MAX_N][MAX_N];

ll rec(int start, int end) {
  if(dp[start][end] != -1) return dp[start][end];
  
  ll tmp1, tmp2;
  tmp1 = tmp2 = 0;
  if(start <= end - 1) tmp1 = -1 * rec(start, end - 1) + a[end];
  if(start + 1 <= end) tmp2 = -1 * rec(start + 1, end) + a[start];
  return dp[start][end] = max(tmp1, tmp2);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> a[i];

  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= N; i++) dp[i][i] = a[i];

  rec(1, N);
  cout << dp[1][N] << endl;
  
  return 0;
}
