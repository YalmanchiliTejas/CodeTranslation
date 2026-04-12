#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;

namespace mp = boost::multiprecision;

#define INF 100000000
#define YJ 1145141919
#define INF_INT_MAX 2147483647
#define INF_LL 9223372036854775
#define INF_LL_MAX 9223372036854775807
#define EPS 1e-10
#define MOD 1000000007
#define MOD9 998244353
#define Pi acos(-1)
#define LL long long
#define ULL unsigned long long
#define LD long double

#define int long long

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a)  begin((a)), end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())

const int MAX_D = 105;
const int MAX_N = 10005;

string K;
int D;
int dp[MAX_N][MAX_D][2];

signed main()
{
  cin >> K;
  cin >> D;

  dp[0][0][0] = 1;
  REP(n,K.size()) {
    REP(d,D) {
      REP(f,2) {
        for(int dd = 0; dd < (f ? 10 : K[n]-'0'+1); dd++) {
          if(f) {
            dp[n+1][(d+dd)%D][f] += dp[n][d][f];
            dp[n+1][(d+dd)%D][f] %= MOD;
          } else {
            if(dd < K[n]-'0') {
              dp[n+1][(d+dd)%D][1] += dp[n][d][f];
              dp[n+1][(d+dd)%D][1] %= MOD;
            } else {
              dp[n+1][(d+dd)%D][0] += dp[n][d][f];
              dp[n+1][(d+dd)%D][0] %= MOD;
            }
          }
        }
      }
      
    }
  }

  cout << (dp[K.size()][0][0] + dp[K.size()][0][1] + MOD - 1) % MOD << endl;

  return 0;
}