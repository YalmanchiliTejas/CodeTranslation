#include <bits/stdc++.h>
using namespace std;
#define int long long

int N;
int a[3000];
int dp[3001][3001];

int rec(int l, int r) {
  if(l>r) return 0;
  if(dp[l][r] != 0xFFFFFFFFFFFFFFFF) return dp[l][r];
  if(l==r) return dp[l][r] = a[l];
  return dp[l][r] = max(a[l] - rec(l+1, r  ), a[r] - rec(l  , r-1));
}

signed main() {
  cin >> N;
  for(int i=0; i<N; i++) cin >> a[i];

  fill((int*)dp, (int*)dp+3001*3001, 0xFFFFFFFFFFFFFFFF);
  int sum = accumulate(a, a+N, 0LL);
  cout << rec(0, N-1) << endl;
}