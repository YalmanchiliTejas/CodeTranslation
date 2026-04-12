#include <regex>
#include "bits/stdc++.h"
#define FOR(i, s, e) for (int i = int(s); i < int(e); ++i)
#define REP(i, e) FOR(i, 0, e)
#define INF (INT_MAX / 2)
#define LINF (LLONG_MAX / 2)
#define EPS (1.0e-8)
#define mkpr make_pair
const int MGN = 2;
const int ARY_SZ_MAX = (int)1e7;
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vd = vector<double>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using psl = pair<string, ll>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S; cin >> S;
  int K; cin >> K;
  int L = S.size();

  auto dp = vector<vvl>(L+MGN, vvl(K + MGN, vl(2, 0)));
  // dp[i][j][k] := S[0,i] (上位から i ) 桁目までを決め、非 0 を j 個使い、
  // そこまでの桁が S と一致していたら k = 0, 一致していないで、既に S
  // の値以下となることが確定していたら k = 1 とするときの通り数
  dp[0][0][0] = 1;

  REP(i, L) {
    REP(j, K + 1) {
      REP(k, 2) {
        const int DMAX = S[i] - '0'; // i 桁目で選択できる最大値
        REP(nd, 10) {
          int ni = i + 1, nj = j, nk = k;
          if (nd > 0) nj++; // 非 0 を使った
          if (nj > K) continue; // 非 0 の使用個数を超えた

          if (k == 0) { // ここまでの桁が上限と一致していたら
            if (nd > DMAX) continue;
            else if (nd == DMAX) nk = 0;
            else {
              assert(nd < DMAX);
              nk = 1;
            }
          }

          dp[ni][nj][nk] += dp[i][j][k];
        }
      }
    }
  }

  ll ans = dp[L][K][0] + dp[L][K][1];
  cout << ans << endl;

  return 0;
}