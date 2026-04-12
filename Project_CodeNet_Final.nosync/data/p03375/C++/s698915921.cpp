#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int64_t mod_pow(int64_t x, int64_t n, int64_t mod) {
  int64_t ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}

vector< vector< int64_t > > get_combination(int N, int mod) {
  vector< vector< int64_t > > mat(N + 1, vector< int64_t >(N + 1));
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) mat[i][j] = 1;
      else mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
      mat[i][j] %= mod;
    }
  }
  return (mat);
}


int N, M;
int64 dp[5000][5000];


int main() {
  cin >> N >> M;
  auto table = get_combination(N, M);

  int64 ret = 0;

  vector< int64 > dp2(N + 2);
  dp2[0] = 1;

  for(int k = 0; k <= N; k++) {
    int64 latte = mod_pow(2, N - k, M), base = 1;
    int64 add = mod_pow(2, mod_pow(2, N - k, M - 1), M);
    for(int j = 0; j <= k; j++) { // 正確にj個選ぶ
      if(k % 2 == 0) ret += add * dp2[j] % M * base % M * table[N][k] % M;
      else ret += M - (add * dp2[j] % M * base % M * table[N][k] % M);
      ret %= M;
      (base *= latte) %= M;
    }
    for(int j = k; j >= 0; j--) {
      dp2[j + 1] += dp2[j];
      dp2[j + 1] %= M;
      dp2[j] += dp2[j] * j % M;
      dp2[j] %= M;
    }
  }
  cout << ret << endl;
}

