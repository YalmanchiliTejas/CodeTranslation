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

const int MAX_N = 3005;
int N;
int A[MAX_N];

int dp[MAX_N][MAX_N];

int solve(int l, int r, int turn) 
{
  if(dp[l][r] != INF_LL) {
    return dp[l][r];
  }

  if(l>r) {
    return 0;
  }

  // cerr << l << " " << r << endl;

  int nextTurn = (turn+1)%2;
  int ret = A[l] - solve(l+1,r,nextTurn);
  ret = max(ret, A[r] - solve(l,r-1,nextTurn));
  return dp[l][r] = ret;
}

signed main()
{
  cin >> N;
  REP(n,N) {
    cin >> A[n];
  }

  REP(n,MAX_N) {
    REP(m,MAX_N) {
      dp[n][m] = INF_LL;
    }
  }
  
  cout << solve(0,N-1,0) << endl;

  return 0;
}
