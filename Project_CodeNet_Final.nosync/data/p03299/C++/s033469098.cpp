#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;
const int mod = 1e9 + 7;

int64_t mod_pow(int64_t x, int64_t n, int64_t mod) {
  int64_t ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}

int64 N, A[100];
int64 dp1[100][101], dp2[100][101];

void dfs(int l, int r) {
  int64 ret = INF;
  int w = r - l;
  for(int i = l; i < r; i++) ret = min(ret, A[i]);
  for(int i = l; i < r; i++) A[i] -= ret;
  vector< pair< int, int > > child;
  for(int i = l; i < r; i++) {
    if(A[i] == 0) continue;
    int left = i;
    while(left < r && A[left] > 0) ++left;
    child.emplace_back(i, left);
    w -= left - i;
    i = left - 1;
  }
  dp1[l][r] = dp2[l][r] = 1;
  for(auto &p : child) {
    dfs(p.first, p.second);
    (dp1[l][r] *= dp1[p.first][p.second]) %= mod;
    (dp2[l][r] *= dp1[p.first][p.second] + dp2[p.first][p.second]) %= mod;
  }
  (dp2[l][r] = dp2[l][r] * mod_pow(2, w, mod) % mod + ((mod_pow(2, ret, mod) + mod - 2) % mod) * dp1[l][r] % mod) %= mod;
  (dp1[l][r] *= mod_pow(2, ret, mod)) %= mod;
  for(int i = l; i < r; i++) A[i] += ret;
}

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  dfs(0, N);
  cout << dp2[0][N] << endl;
}