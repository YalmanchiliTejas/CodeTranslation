#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 59;
const int mod = 1e9 + 7;


int N;
int A[3000];
bool memo[3000][3000];
int64 dp[3000][3000];

int64 rec(int l, int r) {
  if(l > r) return 0;
  if(exchange(memo[l][r], true)) return dp[l][r];
  int64 ret = max(A[r] - rec(l, r - 1), A[l] - rec(l + 1, r));
  return dp[l][r] = ret;
}


int main() {
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  cout << rec(0, N - 1) << endl;
}


