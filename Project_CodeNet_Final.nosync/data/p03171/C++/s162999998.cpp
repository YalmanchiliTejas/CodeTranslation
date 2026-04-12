#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#define rep(i,n) for (int i=0; i<n;++i)
#define rep_down(i,n) for (int i=n-1; i>=0;--i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
const int INF = 1e9+7;
int N;
ll A[3003];
ll DP[3003][3003]; // iからj-1までの区間のときのポイント

int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  rep(i, N) cin >> A[i];
  for (int len = 1; len <= N; ++len) {
    rep(s, N-len+1) {
      int e = s + len;
      if ((N - len) % 2 == 0) DP[s][e] = max(DP[s + 1][e] + A[s], DP[s][e - 1] + A[e - 1]);
      else DP[s][e] = min(DP[s + 1][e] - A[s], DP[s][e - 1] - A[e - 1]);
    }
  }

  cout << DP[0][N] << "\n";
  return 0;
}