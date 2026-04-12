#include <iostream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
typedef long long ll;
const int INF = 1<<30;
const ll MOD = 1e9+7;
const double EPS = 1e-9;

ll inv[500000];

// O(k)
ll modnCk_bigN(int N, int K){
  if (N < K) return 0;
  if (K == 0) return 1;
  ll ret = N;
  inv[1] = 1;
  for (int k=2; k<=K; k++){
    inv[k] = MOD - inv[MOD%k] * (MOD/k) % MOD;
    ret = ret * ((N-k+1) * inv[k] % MOD) % MOD;
  }
  return ret;
}

int main(int argc, const char * argv[]) {
  int N, M, K;
  cin >> N >> M >> K;
  
  ll c = modnCk_bigN(N*M-2, K-2);
  ll ans = 0;
  for (int d=1; d<N; d++)
    ans = (ans + ((c * d % MOD) * (M * M % MOD) % MOD) * (N-d) % MOD) % MOD;
  
  for (int d=1; d<M; d++)
    ans = (ans + ((c * d % MOD) * (N * N % MOD) % MOD) * (M-d) % MOD) % MOD;
  
  cout << ans << endl;
  return 0;
}