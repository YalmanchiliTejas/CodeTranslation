#include <bits/stdc++.h>

using namespace std;

const int N = 3001;

int n;
int arr[N];
long long dp[N][N][2];

long long rec(int i, int j, int t){
  if(i > j) return 0;
  long long& ijt = dp[i][j][t];
  if(ijt != -1) return ijt;
  if(t == 0) ijt = max(rec(i + 1, j, 1 - t) + arr[i], rec(i, j - 1, 1 - t) + arr[j]);
  else ijt = min(rec(i + 1, j, 1 - t) - arr[i], rec(i, j - 1, 1 - t) - arr[j]);
  return ijt;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  memset(dp, -1, sizeof dp);
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  long long ans = rec(0, n - 1, 0);
  cout << ans << "\n";
}