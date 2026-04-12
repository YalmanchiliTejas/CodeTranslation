#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// #define int long long

#define LOG(variable) cout << #variable":\t" << (variable) << endl
#define LOGCON(i, container) for(int (i) = 0; (i) < (container).size(); ++(i)) cout << (i) << ":\t" << (container)[(i)] << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, r, n) for (int i = (r); i < (n); ++i)
#define REPR(i, n) for(int i = (n); i >= 0; --i) // from n to 0
#define REPRS(i, r, n) for(int i = (n); i >= (r); --i) // from n to r
#define REPOBJ(itr, obj) for(auto itr = (obj).begin(); itr != (obj).end() ; ++itr)
#define REPROBJ(itr, obj) for(auto itr = (obj).rbegin(), e = (obj).rend(); itr != e; ++itr)
#define COUTB(x) cout << (x) << "\n"
#define COUTS(x) cout << (x) << " "
#define PB push_back
#define SORT(obj) sort((obj).begin(), (obj).end())
#define SORTR(obj) sort((obj).begin(), (obj).end(), greater<>())
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define PI (acos(-1))
/***** MAIN *****/

int dp[105][4][2];

signed main() {
  string s;
  int K;
  cin >> s;
  cin >> K;
  int n = s.size();
  dp[0][0][0] = 1;
  REP(i,n) REP(j,K+1) REP(k,2) {
    int cur_digit = s[i] - '0';
    REP(pot_digit, 10) {
      int next_i = i+1, next_j = j, next_k = k;
      if(pot_digit) ++next_j;
      if(next_j > K) continue;
      if(next_k == 0) {
        if(pot_digit > cur_digit) continue;
        if(pot_digit < cur_digit) next_k = 1;
      }

      dp[next_i][next_j][next_k] += dp[i][j][k];
    }
  }
  cout << dp[n][K][0] + dp[n][K][1];
  cout << "\n";
  return 0;
}
/***** MAIN *****/
