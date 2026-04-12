// https://atcoder.jp/contests/abc159/tasks/abc159_f

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#if DEBUG
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(b) REP(_j, b.size()) DUMP(b[_j]); cout << endl
#else
  #define DUMP(a)
  #define DUMP2D(b)
#endif

const int N_MAX = 3000;
const int S_MAX = 3000;
const int A_I_MAX = 3000;
const int MOD = 998244353;

int N, S;
vector<int> A;

vector<ll> dp;

int main() {
  cin >> N >> S;
  A = vector<int>(N);
  REP(i, N) cin >> A[i];

  ll ans = 0;
  dp = vector<ll>(S + 1, 0);
  REP(i, N) {
    dp[0] = i + 1;
    dp[S] = 0;
    for (int j = S; j >= A[i]; j--) {
      dp[j] = (dp[j] + dp[j - A[i]]) % MOD;
    }
    ans = (ans + dp[S] * (N - i) % MOD) % MOD;
  }

  cout << ans << endl;
}
