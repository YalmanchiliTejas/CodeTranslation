#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  string N;
  cin >> N;
  long long K;
  cin >> K;

  long long dp[110][2][110];
  REP(i, N.size()) REP(j, 2) REP(k, 110) dp[i][j][k] = 0;
  dp[0][0][0] = 1;

  REP(i, N.size()) {
    const int D = N[i] - '0';
    REP(j, 2) {
      REP(k, 100) {
        for(int d = 0; d <= (j ? 9 : D); d++) {
          dp[i+1][j || (d < D)][k + (d == 0 ? 0 : 1)] += dp[i][j][k];
        }
      }
    }
  }
  cout << dp[N.size()][0][K] + dp[N.size()][1][K] << endl;
  // cout << dp[N.size()][0][K] << endl;
  // cout <<  dp[N.size()][1][K] << endl;
  // REP(i, N.size()) {
  //   REP(j, 2) {
  //     REP(k, K+1) {
  //       cout << dp[i][j][k] << ' ';
  //     }
  //     cout << "    ";
  //   }
  //   cout << endl;
  // }

  

  return 0;
}