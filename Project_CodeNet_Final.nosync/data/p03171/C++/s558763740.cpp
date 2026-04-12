#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
const long long IMPOSSIBLE = 4e18;

long long dp[N][N];
int arr[N];
int n;

void read() {
  cin >> n;
  for (int i = 0 ; i < n ; i++)
    cin >> arr[i];
}

long long solve(int l, int r) {
  if (l > r) return 0;

  int mode = (l + n-1-r) % 2;
  long long &ret = dp[l][r];
  if (ret != IMPOSSIBLE) return ret;

  if (mode == 0) {
    ret = max(arr[l] + solve(l+1, r), arr[r] + solve(l, r-1));
  } else {
    ret = min(solve(l+1, r) - arr[l], solve(l, r-1) - arr[r]);
  }

  return ret;
}

long long work() {
  for (int i = 0 ; i < N ; i++)
    for (int j = 0 ; j < N ; j++)
      dp[i][j] = IMPOSSIBLE;
  
  return solve(0, n-1);
}

int main() {
  read();
  cout << work() << endl;
  return 0;
}